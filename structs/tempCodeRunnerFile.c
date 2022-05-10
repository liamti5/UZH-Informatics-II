pop(s1);
	print(s1);
	Stack *s2 = create(4);
	push(s2, 4);
	push(s2, 2);
	print(s2);
	printf("is equal? %d\n", is_equal(s1, s2));