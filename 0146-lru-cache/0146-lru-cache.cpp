class LRUCache {
public:

    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    int capacity;
    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // Node ko list ke end mein add karo
    void addNode(Node* node) {

        node->next = tail;
        node->prev = tail->prev;

        tail->prev->next = node;
        tail->prev = node;
    }

    // Node ko list se remove karo
    void deleteNode(Node* node) {

        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key) {

        if(mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        // Recently used → end mein move
        deleteNode(node);
        addNode(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if(mp.find(key) != mp.end()) {

            Node* node = mp[key];

            node->value = value;

            deleteNode(node);
            addNode(node);

            return;
        }

        // New node
        Node* node = new Node(key, value);

        mp[key] = node;
        addNode(node);

        // Capacity exceed
        if(mp.size() > capacity) {

            Node* lru = head->next;

            deleteNode(lru);

            mp.erase(lru->key);

            delete lru;
        }
    }
};