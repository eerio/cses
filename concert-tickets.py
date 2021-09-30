from __future__ import annotations
from typing import Optional
from dataclasses import dataclass
from collections import OrderedDict
from bisect import bisect_right, bisect_left

nstr, mstr = input().split()
n, m = int(nstr), int(mstr)

h = list(map(int, input().split()))
t = list(map(int, input().split()))

h.sort()


@dataclass
class BSTNode:
    val: int
    count: int = 1
    left: Optional[BSTNode] = None
    right: Optional[BSTNode] = None


@dataclass
class BST:
    root: Optional[TreeNode] = None

    def is_empty() -> bool:
        return self.root is None
    
    def _insert(self, node: Optional[BSTNode], key: int) -> BSTNode:
        if node is None:
            return BSTNode(key)
        
        if node.val == key:
            node.count += 1
        elif key < node.val:
            node.left = self._insert(node.left, key)
        else:
            node.right = self._insert(node.right, key)
        return node

    def insert(self, key: int) -> None:
        self.root = self._insert(self.root, key)

    def _remove(self, node: BSTNode, key: int) -> Optional[BSTNode]:
        if node.val == key:
            if node.count > 1:
                node.count -= 1
            if node.count == 1:
                if not node.left and not node.right:
                    return None
                elif not node.left or not node.right:
                    return node.right or node.left
                else:
                    if not node.right.left:
                        node.val, node.count = node.right.val, node.right.count
                        node.right = node.right.right
                    else:
                        pre, succ = node.right, node.right.left
                        while succ.left:
                            pre, succ = succ, succ.left

                        node.val, node.count = node.right.val, node.right.count
                        pre.left = None
            else:
                raise Exception('invariant not held')
        elif key < node.val:
            node.left = self._remove(node.left, key)
        else:
            node.right = self._remove(node.right, key)
        return node

    def remove(self, key: int) -> None:
        self.root = self._remove(self.root, key)

    def _find(self, node: Optional[BSTNode], key: int) -> Optional[BSTNode]:
        if node is None:
            return None

        if node.val == key:
            return node
        elif key < node.val:
            return _find(node.left, key)
        else:
            return _find(node.right, key)

    def find(self, key: int) -> Optional[BSTNode]:
        return self._find(self.root, key)

    def _upper_bound(self, node: Optional[BSTNode], key: int) -> Optional[BSTNode]:
        if not node:
            return None
        
        if node.val > key and node.left:
            return self._upper_bound(node.left, key)
        elif node.val <= key and node.right:
            return self._upper_bound(node.right, key)
        return node

    def upper_bound(self, key: int) -> Optional[BSTNode]:
        return self._upper_bound(self.root, key)

    def _lower_bound(self, node: Optional[BSTNode], key: int) -> Optional[BSTNode]:
        if not node:
            return None

        if node.val >= key and node.left:
            return self._lower_bound(node.left, key)
        elif node.val < key and node.right:
            return self._lower_bound(node.right, key)
        return node

    def lower_bound(self, key: int) -> Optional[BSTNode]:
        return self._lower_bound(self.root, key)

    def min_node(self) -> BSTNode:
        node = self.root

        while node and node.left:
            node = node.left

        return node


prices = BST()
for price in h[len(h) // 2: ]:
    prices.insert(price)

for price in h[: len(h) // 2]:
    prices.insert(price)

for budget in t:
    if not prices:
        print(-1)
        continue

    last_leq_node = prices.lower_bound(budget)
    if not last_leq_node:
        print(-1)
    else:
        print(last_leq_node.val)
        prices.remove(last_leq_node.val)
