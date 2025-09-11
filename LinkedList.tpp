template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) { }

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    // TODO
    Node* n= new Node(elem, nullptr);
    if (head == nullptr){
        head = n;
    } else{
        Node* curr = head;
        while (curr->next != nullptr) curr = curr->next;
        curr->next = n;
    }
    ++this->length;
}

template <typename T>
void LinkedList<T>::clear() {
    // TODO
    Node* curr = head;
    while (curr != nullptr){
        Node* nxt = curr->next;
        delete curr;
        curr = nxt;
}
head = nullptr;
this->length = 0;
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    // TODO
    if (position < 0 || position >= this->length){
        throw string("getElement : error, position out of bounds");
    }
    Node* curr = head;
    for (int i = 0; i < position; ++i) curr = curr->next;
    return curr->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    // TODO
    if (position < 0 || position>= this->length){
        throw string("replace: error, position out of bounds");
    }
    Node* curr = head;
    for (int i = 0; i < position; ++i) curr = curr->next;
    curr->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
