for (int i =0 ; i <heap_size-1 ; i++)//main sort
    {
heapify(vec, i, heap_size-i-1);
  swap(vec[0], vec[heap_size - i - 1]);

    }
    