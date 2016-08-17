class HashMapCustom<K, V> {
	
	private Entry<K, V>[] table; //array of entry
	private int capacity = 4;

	static class Entry<K, V> {
		K key;
		V value;
		Entry<K, V> next;
	
		public Entry(K key, V value, Entry<K, V> next) {
			this.key = key;
			this.value = value;
			this.next = next;
		}
	}

	public HashMapCustom() {
		table = new Entry[capacity];
	}

	public void put(K newKey, V data) {
		if(newKey == null)
			return;

		int hash = hash(newKey);
		Entry<K, V> newEntry = new Entry<K, V>(newKey, data, null);

		if(table[hash] == null) {
			table[hash] = newEntry;
		} else {
			Entry<K, V> previous = null;
			Entry<K, V> current = table[hash];


			while(current != null) {
				if(current.key.equals(newKey)) {
					if(previous == null) {
						newEntry.next = current.next;
						table[hash] = newEntry;
						return;
					} else {
						newEntry.next = current.next;
						previous.next = newEntry;
						return;
					}
				}
				previous = current;
				current = current.next;
			}
			previous.next = newEntry;
		}
	}

	public V get(K key) {
		int hash = hash(key);
		if(table[hash] == null) {
			return null;
		} else {
			Entry<K, V> temp = table[hash];
			while(temp != null) {
				if(temp.key.equals(key)) {
					return temp.value;
				}
				temp = temp.next;
			}
			return null;
		}
	}

	public boolean remove(K deleteKey) {
		int hash = hash(deleteKey);

		if(table[hash] == null) {
			return false;
		} else {
			Entry<K, V> previous = null;
			Entry<K, V> current = table[hash];
			
			while(current != null) {
				if(current.key.equals(deleteKey)) {
					if(previous == null) {
						table[hash] = table[hash].next;
						return true;
					} else {
						previous.next = current.next;
						return true;
					}
				}
				previous = current;
				current = current.next;
			}
			return false;
		}
	}

	public void display() {
		for(int i = 0; i < capacity; ++i) { 
			if(table[i] != null) {
				Entry<K, V> entry = table[i];
				while(entry != null) {
					System.out.println("{" + entry.key + "=" + entry.value + "}" + " ");
					entry = entry.next;
				}
			}
		}
	}

	private int hash(K key) {
		return Math.abs(key.hashCode())%capacity;
	}
}


public class HashMapCustomApp {
	public static void main(String[] args) {
		HashMapCustom<Integer, Integer> hashMapCustom = new HashMapCustom<Integer, Integer>();
	
		hashMapCustom.put(21,12);
		hashMapCustom.put(25,121);
		hashMapCustom.put(30,151);
		hashMapCustom.put(33,15);
		hashMapCustom.put(35,89);

		hashMapCustom.display();
	}
}
