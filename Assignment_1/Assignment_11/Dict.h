#pragma once

#include <vector>

using namespace std;

template <class K, class V>
class Dict
{
public:
	/**
	 * @brief Insert an entry, consisting of the pair of variables key of type K and value val of type V.
	 * A console warning is printed if an entry with the same key already exists in the map.
	 * @param key A value that should be used as the key for the key-value pair being entered in to the map
	 * @param val The value variable associated with the key passed.
	 * @pre no such key entered into the map
	 * @post either an entry with the key-value pair is inserted in the map or a message is printed to the console
	*/
	void set(K key, V val)
	{
		if (!this->has(key))
		{
			keys_.push_back(key);
			values_.push_back(val);
			return;
		}
		cout << "An entry with this key already exists in the map!\n";
	}

	/**
	 * @brief Check whether an entry with the following key exists in the map.
	 * @param key the value associated with a value in the map
	 * @pre such a key is entered into the map
	 * @post true is returned if the key is in the map, false otherwise
	*/
	bool has (K key) const
	{
		return std::count(keys_.begin(), keys_.end(), key);
	}

	
	/**
	 * @brief Return the value associated with the key passed. If such a value does not exist, return null.
	 * @param key A value that should be used as the key for the key-value pair being entered in to the map
	 * @pre key is in the dictionary
	 * @post returns the value associated with the specified key, null otherwise
	*/
	V get(K key) const
	{
		return this->has(key) ? values_.at(std::distance(keys_.begin(), std::find(keys_.begin(), keys_.end(), key))) : nullptr;
	}

	/**
	 * @brief Delete the entry with the key passed. If such an entry does not exist, nothing happens.
	 * @param key A value that should be used as the key for the key-value pair being entered in to the map
	 * @pre such a key is entered into the dictionary
	 * @post either an entry with the key is deleted or a message is printed to the console
	*/
	void del(K key)
	{
		if (this->has(key))
		{
			int index = std::distance(keys_.begin(), std::find(keys_.begin(), keys_.end(), key));
			keys_.erase(keys_.begin() + index);
			values_.erase(values_.begin() + index);
			return;
		}
		cout << "An entry with this key does not exist in the map!\n";
	}

	/**
	 * @brief Return all values stored in the map.
	 * @pre Dictionary is initialized
	 * @post a vector with all values is returned
	*/
	std::vector<V> range() const
	{
		return values_;
	}

	
	/**
	 * @brief Returns all the keys stored in the map.
	 * @pre Dictionary is initialized
	 * @post a vector with all keys is returned
	*/
	std::vector<K> domain() const
	{
		return keys_;
	}

private:
	std::vector<V> values_;
	std::vector<K> keys_;
};