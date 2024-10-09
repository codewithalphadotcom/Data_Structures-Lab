# Algorithm to Concatenate Doubly Linked Lists

### Step 1: Check if L is empty
- If L is empty, return M

### Step 2: Check if M is empty
- If M is empty, return L

### Step 3: Attach the tail of L to the head of M
- L.tail.next = M.head
- M.head.prev = L.tail

### Step 4: Update the tail of the resulting list
- L.tail = M.tail

### Step 5: Return the head of the resulting list
- return L.head