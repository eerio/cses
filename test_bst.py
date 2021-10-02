from bst import BST

tree = BST()

#   100
# 50  200
#    175 225
for x in [100, 50, 200, 175, 225]:
    tree.insert(x)

val_layers = [[node.val for node in layer] for layer in tree.layers()]
assert val_layers == [[100], [50, 200], [175, 225]]
assert not tree.is_empty()


for x in [100, 50, 200, 175, 225]:
    assert tree.find(x).val == x

assert tree.min_node().val == 50

assert tree.upper_bound(200).val == 225
assert tree.upper_bound(225) is None
assert tree.lower_bound(50).val == 50
assert tree.lower_bound(40).val == 50
assert tree.lower_bound(180).val == 175

assert tree.lower_bound(250).val == 225
assert tree.upper_bound(250) is None


#                100
#          50          200
#    -100     75     175   225
# -200   0
for x in [-100, -200, 0, 75]:
    tree.insert(x)

val_layers = [[node.val for node in layer] for layer in tree.layers()]
assert val_layers == [[100], [50, 200], [-100, 75, 175, 225], [-200, 0]]

#                100
#          75          200
#    -100           175   225
# -200
for x in [0, 50]:
    tree.remove(x)

val_layers = [[node.val for node in layer] for layer in tree.layers()]
assert val_layers == [[100], [75, 200], [-100, 175, 225], [-200]]

#                100
#          75          200
#    -100           175   225
for x in [-200]:
    tree.remove(x)

val_layers = [[node.val for node in layer] for layer in tree.layers()]
assert val_layers == [[100], [75, 200], [-100, 175, 225]]
assert not tree.is_empty()


#           175
#       75      200
#  -100               225
tree.remove(100)

val_layers = [[node.val for node in layer] for layer in tree.layers()]
assert val_layers == [[175], [75, 200], [-100, 225]]
assert not tree.is_empty()


tree.remove(-100)
val_layers = [[node.val for node in layer] for layer in tree.layers()]
assert val_layers == [[175], [75, 200], [225]]
assert not tree.is_empty()

tree.remove(200)
val_layers = [[node.val for node in layer] for layer in tree.layers()]
assert val_layers == [[175], [75, 225]]
assert not tree.is_empty()

tree.remove(175)
tree.remove(225)

val_layers = [[node.val for node in layer] for layer in tree.layers()]
assert val_layers == [[75]]
assert not tree.is_empty()

# insert again
tree.insert(75)

tree.remove(75)
val_layers = [[node.val for node in layer] for layer in tree.layers()]
assert val_layers == []
assert not tree.is_empty()

tree.remove(75)
val_layers = [[node.val for node in layer] for layer in tree.layers()]
assert val_layers == []
assert tree.is_empty()


print(tree.layers())
print(tree.root)
