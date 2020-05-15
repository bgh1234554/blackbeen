package cse2010.homework2;

/*
 * © 2020 CSE2010 HW #2
 *
 * DO NOT MODIFY THIS CLASS!
 */
class Node<T> {
    private T info;
    private Node<T> next;
    private Node<T> prev;

    Node(T info) {
        this(info, null, null);
    }

    Node(T info, Node<T> prev, Node<T> next) {
        this.info = info;
        this.prev = prev;
        this.next = next;
    }

    T getInfo() {
        return info;
    }

    void setInfo(T info) {
        this.info = info;
    }

    Node<T> getNext() {
        return next;
    }

    void setNext(Node<T> n) {
        next = n;
    }

    Node<T> getPrev() {
        return prev;
    }

    void setPrev(Node<T> p) {
        prev = p;
    }

    @Override public String toString() {
        return "Node{" +
                "info=" + info +
                ", next=" + next +
                ", prev=" + prev +
                '}';
    }
}
