#include "LinkedStack.h"  // Stack class specification file
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr){}

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack){
    shared_ptr<Node<ItemType>> origChainPtr = aStack.topPtr;

    if(origChainPtr == nullptr)
        topPtr = nullptr;
    else
    {
        topPtr = make_shared<Node<ItemType>>();
        topPtr->setItem(origChainPtr->getItem());

        shared_ptr<Node<ItemType>> newChainPtr = topPtr;

        origChainPtr = origChainPtr->getNext();

        while(origChainPtr != nullptr){
            ItemType nextItem = origChainPtr->getItem();
            shared_ptr<Node<ItemType>> newNodePtr = make_shared<Node<ItemType>>(nextItem);
            newChainPtr->setNext(newNodePtr);
            newChainPtr = newChainPtr->getNext();
            origChainPtr = origChainPtr->getNext();
        }

        newChainPtr->setNext(nullptr);
    }
}

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack() {
    while(!isEmpty())
        pop();
}

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const {
    return topPtr == nullptr;
}

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newEntry){
    shared_ptr<Node<ItemType>> newNodePtr = make_shared<Node<ItemType>>(newEntry, topPtr);
    topPtr = newNodePtr;
    newNodePtr = nullptr;

    return true;
}

template<class ItemType>
bool LinkedStack<ItemType>::pop(){
    if(!isEmpty()){
        shared_ptr<Node<ItemType>> nodeToDeletePtr = topPtr;
        topPtr = topPtr->getNext();

        nodeToDeletePtr->setNext(nullptr);
//        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;

        return true;
    }
    return false;
}

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const{
    if(isEmpty())
        throw(PrecondViolatedExcep("peek() called with empty stack."));

    return topPtr->getItem();
}



