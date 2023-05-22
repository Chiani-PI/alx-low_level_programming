#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - Function to initializs a variable of type struct dog
 * @d: The pointer to struct dog to be initialized
 * @name: The name to be initialized
 * @age: The age to be initialized
 * @owner: The owner to be initialized
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		d = malloc(sizeof(struct dog));
	d->name = name;
	d->age = age;
	d->owner = owner;
}
