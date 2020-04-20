#pragma once

#include <vector>

template <class K, class V>
class Dict
{
public:
	Dict()
	{
		this->values_ = {};
		this->keys_ = {};
	}
	/**
	 * @brief Insert an entry, consisting of the pair of variables key of type K and the value val of type V.
	 * Nothing happens if an entry with the same key already exists in the map.
	 * @param key A value that should be used as the key for the key-value pair being entered in to the map
	 * @param val The value variable associated with the key passed.
	 * @pre no such key entered into the map
	 * @post either an entry with the key-value pair is inserted in the map or nothing happens
	*/
	void set(K key, V val)
	{
		if (!this->has(key))
		{
			keys_.push_back(key);
			values_.push_back(val);
		}
	}

	/**
	 * @brief Check whether an entry with the following key exists in the map.
	 * @param key the value associated with a value in the map
	 * @pre such a key is entered into the map
	 * @post true is returned if the key is in the map
	*/
	bool has (K key) const
	{
		return std::count(keys_.begin(), keys_.end(), key);
	}

	
	/**
	 * @brief Return the value associated with the key passed. If such a value does not exist, return null.
	 * @param key A value that should be used as the key for the key-value pair being entered in to the map
	 * @pre there is such a kit in the map
	 * @post returns the value associated with the specified key
	*/
	V get(K key) const
	{
		return this->has(key) ? values_.at(std::distance(keys_.begin(), std::find(keys_.begin(), keys_.end(), key))) : nullptr;
	}

	/**
	 * @brief Delete the entry with the key passed. If such an entry does not exist, nothing happens.
	 * @param key A value that should be used as the key for the key-value pair being entered in to the map
	 * @pre such a key is entered into the map
	 * @post either an entry with the key-value pair is deleted in the map or nothing happens
	*/
	void del(K key)
	{
		if (this->has(key))
		{
			int index = std::distance(keys_.begin(), std::find(keys_.begin(), keys_.end(), key));
			keys_.erase(keys_.begin() + index);
			values_.erase(values_.begin() + index);
		}
	}

	/**
	 * @brief // Return all values stored in the map.
	 * @post either an entry with the key-value pair is inserted in the map or nothing happens
	*/
	const std::vector<V> range()
	{
		return values_;
	}

	
	/**
	 * @brief Returns all the keys stored in the map.
	 * @pre no such key entered into the map
	 * @post either an entry with the key-value pair is inserted in the map or nothing happens
	*/
	const std::vector<K> domain()
	{
		return keys_;
	}

private:
	std::vector<V> values_;
	std::vector<K> keys_;
};