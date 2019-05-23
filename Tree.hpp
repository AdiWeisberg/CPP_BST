using namespace std;

namespace ariel{
        struct Node{
            public:
            int data;
            Node* leftChild;
            Node* rightChild;
            Node* parent;
            Node(int value){
                data=value;
                leftChild=NULL;
                rightChild=NULL;
                parent=NULL;
            }
        };

        

        class Tree {
        public:

        struct Node* node_root;
        int count;
        
        Tree();
        ~Tree();

        void insert(int value);
        void remove(int value);
        int size();
        bool contains(int value);
        int root();
        int parent(int value);
        int left(int value);
        int right(int value);
        void print();

        private:
            void insert(int value,Node *current);
	        Node* search(int value,Node *current);
	        bool contain(int value,Node *current);
            void inorder(Node *root);
            void destroy(Node* Tree);
            Node* FindMax(Node* nodeMaxVal);
            void remove(Node* &node, int num);


    
        };
    }
