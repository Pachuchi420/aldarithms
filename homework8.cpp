int findRank(int k){ 
    if root is null:
        return bottom

    rank = 0 
    node = root

    while node is not null: 

        leftSize = 0; 
        if node has left child: 
            leftSize = size of left child

        for each key in node:
            if k == key:  
                return rank + leftSize + position of key in node 
            else if k < key: 
                node = left child of key
                break
            else: 
                rank = rank + leftSize + 1 + number of keys less than k in node
                leftSize = 0 
                node = right child of key

    return bottom
}   




