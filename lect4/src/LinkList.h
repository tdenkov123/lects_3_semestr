#pragma once

#include <iostream>
#include <optional>

using namespace std;

template <typename T> class LinkList {
    private:
        struct Node {
            Node* next;
            T data;
            Node(T pData) : data(pData), next(nullptr) {}; 
        } *head;
    public:
        LinkList() : head(nullptr) {}
        LinkList(LinkList&& p_list) {
            head = p_list.head;
        }
        ~LinkList() {
            Node* curr = head;
            while (curr) {
                Node* next = curr->next;
                free(curr);
                curr = next; 
            }
        }

        void InsertNode(Node* newNode, int position) {
            Node* tmp = head;
            if (head) {
                if (position == 0) {
                    newNode->next = head;
                    head = newNode;
                } else {
                    while (position--) {
                        if (!tmp->next) {
                            break;
                        }
                        tmp = tmp->next;
                    }
                    newNode->next = tmp->next;
                    tmp->next = newNode;

                }
            } else {
                head = newNode;
            }
        }

        void appendElement(T data, int position) {
            InsertNode(new Node(data), position);
        }

        void RemoveNode(int position) {
            Node* tmp = head;
            Node* prev = nullptr;
            if (tmp) {
                if (position == 0) {
                    head = head->next;
                } else {
                    while (position--) {
                        if (!tmp->next) {
                            break;
                        }
                        prev = tmp;
                        tmp = tmp->next;
                    }
                    prev->next = tmp->next;
                }
                free(tmp);
            }
        }

        optional<T> GetElement(size_t position) {
            Node* curr = head;
            size_t pos = 0;
            while (curr->next) {
                if (pos == position) {
                    return curr->data;
                    break;
                }
                pos++;
                curr = curr->next;
            }
            return nullopt;
        }

        void PrintList() {
            Node* tmp = head;
            while (tmp) {
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
            cout << "\n";
        }
};