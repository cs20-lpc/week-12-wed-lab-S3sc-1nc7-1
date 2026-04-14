template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
    // TO DO:
    for(int i = 0; i < M; i++){
        int place = probeIndex(key, i);
        if(!occupied[place]){
            table[place] = key;
            occupied[place] = true;
            N ++;
            return place;
        }
        else if (table[place] == key){
            return place;
        }
    }
    throw string("Array Full, Slot not Found!");
}

template <typename T>
pair<bool, int> HashTableClosed<T>::search(const T& key) const
{
    // TO DO: 
    for(int i = 0; i < M; i++){
        int place = probeIndex(key, i);

        if(!occupied[place]){
            return {false, 0};
        }
        else if (table[place] == key){
            return{true, place};
        }
    }
    return {false, 0};
}
