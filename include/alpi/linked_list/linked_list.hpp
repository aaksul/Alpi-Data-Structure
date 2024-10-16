#pragma once

#include <initializer_list>
#include <iostream>
#include <memory>
#include <iterator>

namespace alpi {
template <class T> class linked_list {

  struct list_node;

  using node_ref = std::shared_ptr<list_node>;

  struct list_node {
    T value_;
    node_ref next_;
  };

public:
  linked_list()
      : head_{nullptr}, tail_{nullptr}, EOL_NODE{new list_node{T{}, nullptr}} {}

  linked_list(std::initializer_list<T> list) {
    for (auto el : list) {
      add(el);
    }
  }

  linked_list(const linked_list& other) {
      for (auto el : other){
        add(el);
      }
  }

  linked_list& operator=(const linked_list& other) {
      head_.reset();
      tail_.reset();
      for (auto el : other){
        add(el);
      }
      return *this;
  }

  linked_list(linked_list&& other) = default;

  linked_list& operator=(linked_list&& other) = default;

  ~linked_list() = default;

  void add(const T &value) {
    node_ref new_node{new list_node{value, EOL_NODE}};
    if (head_ == nullptr && tail_ == nullptr) {
      head_ = new_node;
      tail_ = new_node;
      return;
    }
    tail_->next_ = new_node;
    tail_ = new_node;
  }

  struct iterator {

    iterator() : cur_{nullptr} {}

    iterator(std::shared_ptr<list_node> node_ref) : cur_{node_ref.get()} {}

    iterator operator++(int) { // left++
      iterator old = *this;
      ++(*this);
      return old;
    }

    iterator &operator++() { // right
      if (cur_ != nullptr) {
        cur_ = cur_->next_.get();
      }
      return *this;
    }

    T &operator*() { return cur_->value_; }
    T &operator*() const { return cur_->value_; }

    bool operator==(const iterator &other) const {
      if (cur_ == other.cur_) {
        return true;
      }
      return false;
    }

    bool operator!=(const iterator &other) const { return !(*this == other); }

  private:
    list_node *cur_;
  };
  
  struct const_iterator {

    const_iterator(std::shared_ptr<list_node> node_ref) : cur_{node_ref.get()} {}

    const_iterator operator++(int) { // left++
      const_iterator old = *this;
      ++(*this);
      return old;
    }

    const_iterator& operator++() { // right
      if (cur_ != nullptr) {
        cur_ = cur_->next_.get();
      }
      return *this;
    }
    
    const T& operator*() const { return cur_->value_; }

    bool operator==(const const_iterator &other) const {
      if (cur_ == other.cur_) {
        return true;
      }
      return false;
    }

    bool operator!=(const const_iterator &other) const { return !(*this == other); }

  private:
    const list_node *cur_;
  };

  void merge(linked_list &other) {
    node_ref ordered_pos{new list_node{T{}, nullptr}};
    node_ref headtmp = ordered_pos;
    node_ref pos = head_;
    node_ref pos2 = other.head_;

    while (pos != EOL_NODE && pos2 != other.EOL_NODE) {
      node_ref insert_node{};
      if (pos2->value_ < pos->value_) {
        insert_node = pos2;
        pos2 = pos2->next_;
      } else {
        insert_node = pos;
        pos = pos->next_;
      }
      ordered_pos->next_ = insert_node;
      ordered_pos = insert_node;
    }

    while (pos != EOL_NODE) {
      ordered_pos->next_ = pos;
      ordered_pos = pos;
      pos = pos->next_;
    }

    while (pos2 != other.EOL_NODE) {
      ordered_pos->next_ = pos2;
      ordered_pos = pos2;
      pos2 = pos2->next_;
    }

    head_ = headtmp->next_;
    tail_ = ordered_pos;
  }

  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;

private:
  node_ref head_;
  node_ref tail_;
  node_ref EOL_NODE;
};

} // namespace alpi

template <typename T>
typename alpi::linked_list<T>::iterator alpi::linked_list<T>::begin() {
  return linked_list<T>::iterator(head_);
}

template <typename T>
typename alpi::linked_list<T>::const_iterator alpi::linked_list<T>::begin() const {
  return linked_list<T>::const_iterator(head_);
}

template <typename T>
typename alpi::linked_list<T>::const_iterator alpi::linked_list<T>::end() const {
  auto it = linked_list<T>::const_iterator(tail_);
  it++;
  return it;
}

template <typename T>
typename alpi::linked_list<T>::iterator alpi::linked_list<T>::end() {
  auto it = linked_list<T>::iterator(tail_);
  it++;
  return it;
}
