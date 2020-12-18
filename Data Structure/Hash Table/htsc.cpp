#include <iostream>
#include <list>
#include <vector>
#include <cmath>

using namespace std;

template <typename K, typename V>
class Entry
{
public:
    int hash_value;
    K key;
    V value;

public:
    Entry(K key, V value)
    {
        this->key = key;
        this->value = value;
        hash<K> hashcode;
        this->hash_value = hashcode(key);
    }

    bool equals(Entry<K, V> other)
    {
        return this->hash_value == other.hash_value;
    }
};

static const int DEFAULT_CAPACITY = 3;
static const double DEFAULT_LOAD_FACTOR = 0.75;

template <typename K, typename V>
class htsc
{

private:
    double maxLoadFactor;
    int capacity, threshold, size = 0;
    vector<list<Entry<K, V>>> table;

    hash<K> hashcode;

public:
    htsc() : htsc(DEFAULT_CAPACITY, DEFAULT_LOAD_FACTOR)
    {
    }

    htsc(int capacity) : htsc(capacity, this->DEFAULT_LOAD_FACTOR)
    {
    }

    // designated constructor
    htsc(int cap, double load_factor)
    {
        if (cap <= 0)
            throw invalid_argument("Illegal capacity: " + to_string(cap));

        if (load_factor <= 0 || isnan(load_factor) || isinf(load_factor))
        {
            throw invalid_argument("Illegal load Factor: " + to_string(load_factor));
        }

        maxLoadFactor = load_factor;
        capacity = max(DEFAULT_CAPACITY, cap);
        threshold = (int)(maxLoadFactor * this->capacity);

        list<Entry<K, V>> bucket;
        this->table.assign(this->capacity, bucket);
    }

    int length()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void clear()
    {
        list<Entry<K, V>> bucket;
        this->table.assign(this->capacity, bucket);
        size = 0;
    }

    bool containsKey(K key)
    {
        return hasKey(key);
    }

    bool hasKey(const K &key)
    {
        int bucketIndex = normalizeIndex(hashcode(key));
        return bucketSeekEntry(bucketIndex, key) != NULL;
    }

    void add(const K &key, const V &value)
    {
        insert(key, value);
    }

    void insert(const K &key, const V &value)
    {
        Entry<K, V> newEntry(key, value);
        int bucketIndex = normalizeIndex(newEntry.hash_value);
        bucketInsertEntry(bucketIndex, newEntry);
    }

    void remove(const K &key)
    {
        int bucketIndex = normalizeIndex(hashcode(key));
        bucketRemoveEntry(bucketIndex, key);
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Hash Table is empty";
            return;
        }
        int i = 0;
        cout << endl
             << "Hash table contains:" << endl;
        for (auto bucket : table)
        {
            if (!bucket.empty())
            {
                cout << endl
                     << "Index: " << i << endl;
                for (auto entry : bucket)
                {
                    cout << entry.key << " : " << entry.value << endl;
                }
                cout << endl;
            }
            i++;
        }
    }

    void display()
    {
        cout << *this;
    }

    V get(const K &key)
    {
        int bucketIndex = normalizeIndex(hashcode(key));
        Entry<K, V> *entry = bucketSeekEntry(bucketIndex, key);

        if (entry != NULL)
            return entry->value;

        //return V();
        throw runtime_error("Key doesn't exists!");
    }

    vector<K> getkeys()
    {
        vector<K> keys;

        for (auto bucket : table)
        {
            if (!bucket.empty())
            {
                for (auto entry : bucket)
                {
                    keys.push_back(entry.key);
                }
            }
        }

        return keys;
    }

    V &operator[](const K &key)
    {

        int bucketIndex = normalizeIndex(hashcode(key));

        Entry<K, V> *entry = bucketSeekEntry(bucketIndex, key);
        if (entry != NULL)
        {
            return entry->value;
        }

        Entry<K, V> newEntry(key, V());
        bucketInsertEntry(bucketIndex, newEntry);
        Entry<K, V> *existentEntry = bucketSeekEntry(bucketIndex, key);
        return existentEntry->value;
    }

    template <typename K1, typename V1>
    friend ostream &operator<<(ostream &os, const htsc<K1, V1> &t);

private:
    int normalizeIndex(int keyHash)
    {
        return (keyHash & 0x7FFFFFFF) % capacity;
    }

    void bucketInsertEntry(int bucketIndex, Entry<K, V> &entry)
    {

        list<Entry<K, V>> *bucket = &table[bucketIndex];

        Entry<K, V> *existentEntry = bucketSeekEntry(bucketIndex, entry.key);

        if (existentEntry == NULL)
        {
            bucket->push_back(entry);
            if (++size > threshold)
                resizeTable();
        }
        else
        {
            existentEntry->value = entry.value;
        }
    }

    void bucketRemoveEntry(int bucketIndex, const K &key)
    {
        list<Entry<K, V>> *bucket = &table[bucketIndex];
        auto itr = bucket->begin();
        for (; itr != bucket->end(); itr++)
        {
            if (itr->key == key)
                break;
        }

        if (itr != bucket->end())
        {
            --size;
            bucket->erase(itr);
        }
    }

    void resizeTable()
    {

        capacity *= 2;
        threshold = (int)(capacity * maxLoadFactor);

        vector<list<Entry<K, V>>> newTable;
        list<Entry<K, V>> bucket;
        newTable.assign(capacity, bucket);

        for (auto bucket : table)
        {
            if (!bucket.empty())
            {
                for (Entry<K, V> entry : bucket)
                {
                    int bucketIndex = normalizeIndex(entry.hash_value);
                    list<Entry<K, V>> *bucketList = &newTable[bucketIndex];
                    bucketList->push_back(entry);
                }
            }
        }

        table = newTable;
    }

    Entry<K, V> *bucketSeekEntry(int bucketIndex, const K &key)
    {

        list<Entry<K, V>> *bucket = &table[bucketIndex];

        if (bucket->empty())
            return NULL;

        for (auto itr = bucket->begin(); itr != bucket->end(); itr++)
        {
            Entry<K, V> *entry = &*itr;

            if (entry->key == key)
                return entry;
        }

        return NULL;
    }
};

// template fucntion that has access to private member to overload << for htsc class object
template <typename K, typename V>
ostream &operator<<(ostream &os, const htsc<K, V> &t)
{
    int i = 0;
    os << "[ ";

    for (auto bucket : t.table)
    {
        if (!bucket.empty())
        {
            for (auto entry : bucket)
            {
                os << "{" << entry.key << ":" << entry.value << "}";
                i++;
                if (i != t.size)
                {
                    os << ", ";
                }
            }
        }
    }

    os << " ]" << endl;

    return os;
}

int main()
{
    htsc<string, int> ht;
    ht["Success"] = 200;
    ht["Yeah"] = 31;
    ht.display();
}
