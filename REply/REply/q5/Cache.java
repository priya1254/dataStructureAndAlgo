/**
 * Created by ramakantagrawal on 11/02/17.
 */
package q5;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;

public class Cache {

    class Entry {
        int data;
        Entry next;
        Entry last;
    }

    private Entry head, tail;
    private int cacheSize;

    public Cache(int cacheSize) {
        this.cacheSize = cacheSize;
    }

    Map<Integer, Entry> cache = new HashMap<Integer, Entry>();
    LinkedList<Entry> list = new LinkedList<Entry>();

    void removeEntry(Entry e) {
        if (e.last == null) {
            head = e.next;
        } else {
            e.last.next = e.next;
        }
        if (e.next == null) {
            tail = e.last;
        } else {
            e.next.last = e.last;
        }
    }

    void addFirst(Entry e) {
        e.last = null;
        e.next = head;
        if (head != null) {
            head.last = e;
        }
        head = e;
        if (tail == null) {
            tail = e;
        }
    }

    Integer get(Integer value) {
        if (cache.containsKey(value)) {
            Entry entry = cache.get(value);
            removeEntry(entry);
            addFirst(entry);
            return entry.data;
        } else {
            return null;
        }
    }

    void set(Integer newValue) {
        Integer value = get(newValue);
        Entry newEntry = new Entry();
        newEntry.data = newValue;
        if (value == null && cache.size() == cacheSize) {
            cache.remove(value);
            removeEntry(tail);
        }
        addFirst(newEntry);
        cache.put(newValue, newEntry);
    }

}

/*
a) LRU cache replaces the least recently used values while adding a new entry to the cache. LRU cache keeps track of access time(age bit) and replaces the oldest entry if cache is full while adding a new value. When a key A is requested from the cache if the key is found in the cache its age bit will be updated to the current time stamp. An eviction stratergy decides which element to remove from a full cache while adding a new element to cache. e.g. LRU removes least recently used item, LFU removes least frequently used element.

b) implemented above
c) implemented above

d) We can synchronize the update operation on the cache(by taking locking cache object monitor) such that only one client updates the cache while reads can be done parallely.

e) To make the cache distributed, we can use value hashing at cache level such one different values bucket to differt caches.

 */