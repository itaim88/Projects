
#include <stdio.h>/*printf*/
#include <stdlib.h>/*malloc*/

typedef void (*vfunc_t)(void *);

typedef enum vMetods{CLONE, EQUALS, GET_CLASS, HASH_CODE,
	                NOTIFY, NOTIFY_ALL, WAIT, TO_STRING,
	                FINALIZE, NUM_MASTERS, SAY_HELLO
                    } vmethods_t;

/*******************Java2C function ******************/

void objectClone(void *pointer);
void objectEquals(void *pointer);
void objectFinalize(void *pointer);
void objectGetClass(void *pointer);
void objectHashCode(void *pointer);
void objectNotify(void *pointer);
void objectNotifyAll(void *pointer);
void objectToString(void *pointer);
void objectWait(void *pointer);
void animalSayHello(void *pointer);
void animalGetNumMasters(void *pointer);
void animalToString(void *pointer);
void animalFinalize(void *pointer);
void dogSayHello(void *pointer);
void dogFinalize(void *pointer);
void dogToString(void *pointer);
void catFinalize(void *pointer);
void catToString(void *pointer);
void catSayHello(void *pointer);
void legendaryToString(void *pointer);
void legendaryFinalize(void *pointer);
void legenderySayHello(void *pointer);

/********************vfunc_tables & structs***********************/

vfunc_t object_Vtable[] = {objectClone, objectEquals, objectGetClass,
                            objectHashCode, objectNotify, objectNotifyAll,
                			objectWait,objectToString, objectFinalize};

vfunc_t animal_Vtable[] = {objectClone,objectEquals, objectGetClass,
                            objectHashCode, objectNotify, objectNotifyAll,
                            objectWait, animalToString, animalFinalize,
                            animalGetNumMasters, animalSayHello};
							
vfunc_t dog_Vtable[] = {objectClone, objectEquals, objectGetClass,
                		objectHashCode, objectNotify, objectNotifyAll,
                		objectWait, dogToString, dogFinalize,
                		animalGetNumMasters, dogSayHello};
						
vfunc_t cat_Vtable[] = {objectClone, objectEquals, objectGetClass,
                        objectHashCode, objectNotify, objectNotifyAll,
                        objectWait, catToString, catFinalize,
                        animalGetNumMasters, animalSayHello};

vfunc_t legendary_Vtable[] = {objectClone, objectEquals, objectGetClass,
				                objectHashCode, objectNotify, objectNotifyAll,
					            objectWait, legendaryToString, legendaryFinalize,
				                animalGetNumMasters, legenderySayHello};
				                
typedef struct Class{
	char *name;
	size_t size;
	struct Class *super;
	vfunc_t (*class_Vtable)[];
} class_t;

typedef struct Object{
	class_t *metadata;
} object_t;

typedef struct Animal{
	object_t obj;
	int num_legs;
	int num_masters;
	int ID;
} animal_t;

typedef struct Dog {
	animal_t animal;
	int num_legs;
} dog_t;

typedef struct Cat {
	animal_t animal;
	char *colors;
	int num_masters;
} cat_t;

typedef struct LegendaryAnimal {
	cat_t cat;
} legendary_t;

int counter = 0;

typedef struct Wrapper {
	object_t *this;
	int num_masters;
	char *string_result;
} wrapper_t;

/***************************metadata****************************/

class_t object_meta = {"Object", sizeof(object_t), NULL, &object_Vtable};
class_t animal_meta = {"Animal", sizeof(animal_t), &object_meta, &animal_Vtable};
class_t dog_meta = {"Dog", sizeof(dog_t), &animal_meta, &dog_Vtable};
class_t cat_meta = {"Cat", sizeof(cat_t), &animal_meta, &cat_Vtable};
class_t legendary_meta = {"LegendaryAnimal", sizeof(legendary_t), &animal_meta, &legendary_Vtable};

/************************Implementatin**************************/

void objectClone(void *pointer)
{
    printf("this is java.lang.Object Clone()\n");
}
void objectEquals(void *pointer)
{
    printf("this is java.lang.Object Equals()\n");
}
void objectFinalize(void *pointer)
{
    printf("this is java.lang.Object Finalize()\n");
}
void objectGetClass(void *pointer)
{
    printf("this is java.lang.Object Finalize()\n");
}
void objectHashCode(void *pointer)
{
    printf("this is java.lang.Object HashCode()\n");
}
void objectNotify(void *pointer)
{
    printf("this is java.lang.Object Notify()\n");
}
void objectNotifyAll(void *pointer)
{
    printf("this is java.lang.Object NotifyAll()\n");
}
void objectWait(void *pointer)
{
    printf("this is java.lang.Object Wait()\n");
}
void animalFinalize(void *pointer)
{
    printf("this is animal Finalize()\n");
}
void dogFinalize(void *pointer)
{
    printf("this is dog Finalize()\n");
}
void catFinalize(void *pointer)
{
    printf("this is cat Finalize()\n");
}

void legendaryFinalize(void *pointer)
{
   printf("this is egendary Finalize()\n"); 
}

void showCounter()
{
	printf("%d\n", counter);
}

void foo(animal_t *animal, wrapper_t param)
{
	(*animal->obj.metadata->class_Vtable)[TO_STRING](&param);
	printf("%s\n", param.string_result);
	free(param.string_result);
}


void objectToString(void *pointer)
{
	sprintf(((wrapper_t *)pointer)->string_result, "%s@%lu", 
		    ((object_t *)((wrapper_t *)pointer)->this)->metadata->name, 
	    	(size_t)(((wrapper_t *)pointer)->this));
}


void animalSayHello(void *pointer)
{
	printf("Animal Hello!\n");
	printf("I have %d legs\n", ((animal_t *)((wrapper_t *)pointer)->this)->num_legs);
}

void animalGetNumMasters(void *pointer)
{
			((wrapper_t *)pointer)->num_masters =
		((animal_t *)((wrapper_t *)pointer)->this)->num_masters;
}

void animalToString(void *pointer)
{
	((wrapper_t *)pointer)->string_result = (char *) malloc(sizeof(char) * 80);
	
	sprintf(((wrapper_t *)pointer)->string_result, 
	        "Animal with ID: %d", ((animal_t *)((wrapper_t *)pointer)->this)->ID);
}

void dogSayHello(void *pointer)
{
	printf("Dog Hello!\n");
	printf("I have %d legs\n", ((dog_t *)((wrapper_t *)pointer)->this)->num_legs);
}


void dogToString(void *pointer)
{
	((wrapper_t *)pointer)->string_result = (char *)malloc(sizeof(char) * 80);
	sprintf(((wrapper_t *)pointer)->string_result, "Dog with ID: %d", 
			((dog_t *)((wrapper_t *)pointer)->this)->animal.ID);
}


void catToString(void *pointer)
{
	((wrapper_t *)pointer)->string_result = (char *)malloc(100);
	sprintf(((wrapper_t *)pointer)->string_result, "Cat with ID: %d",
	 		((cat_t *)((wrapper_t *)pointer)->this)->animal.ID);
}

void legendaryToString(void *pointer)
{
	((wrapper_t *)pointer)->string_result = (char *)malloc(100);
	sprintf(((wrapper_t *)pointer)->string_result, "LegendaryAnimal with ID: %d", 
			((animal_t *)((wrapper_t *)pointer)->this)->ID);
}

void legenderySayHello(void *pointer)
{
	printf("Legendary Hello!\n");
}

/****************Classes & Constructors*****************************************/
object_t *objectAlloc(class_t *class)
{
	object_t *obj = (object_t *)malloc(class->size);
	obj->metadata = class;
	
	return obj;
}

void animalCtor(wrapper_t param, int *num_masters)
{
	animal_t *animal = (animal_t *)(param.this);
	static int static_block = 0;
	
	if (0 == static_block)
	{
		printf("Static block Animal 1\n");
		printf("Static block Animal 2\n");
		++static_block;
	}
	
	printf("Instance initialization block Animal\n");

	
	animal->ID = ++counter;
	animal->num_legs = 5;
	
	if (num_masters == NULL)
	{
		printf("Animal Ctor\n");
		animal->num_masters = 1;
		(*animal->obj.metadata->class_Vtable)[SAY_HELLO](&param);
		showCounter(NULL);
		(*animal->obj.metadata->class_Vtable)[TO_STRING](&param);
		printf("%s\n", param.string_result);
		objectToString(&param);
		printf("%s\n", param.string_result);
		free(param.string_result);
	}
	
	else 
	{
		printf("Animal Ctor int\n");
		animal->num_masters = *num_masters;
	}
}

void dogCtor(wrapper_t param)
{
	dog_t *dog = (dog_t *)(param.this);
	int i = 2;
	static int static_block = 0;
	
	if(0 == static_block)
	{
		printf("Static block Dog\n");
		++static_block;
	}

	animalCtor(param, &i);
	printf("Instance initialization block Dog\n");
	printf("Dog Ctor\n");
	dog->num_legs = 4;
}

void catCtor(wrapper_t param, char *cat_color)
{
	cat_t *cat = (cat_t *)(param.this);
	static int static_block = 0;
	animal_t *animal = NULL;

	cat->num_masters = 5;
	
	if (0 == static_block)
	{
		printf("Static block Cat\n");
		++static_block;
	}
	
	if (cat_color == NULL)
	{
		catCtor(param, "black");
		cat->num_masters = 2;
		printf("Cat Ctor\n");
	}
	
	else
	{
		animalCtor(param, NULL);
		cat->colors = cat_color;
		printf("Cat Ctor with color: %s\n", cat_color);
	}
}

void legendaryCtor(wrapper_t param)
{
	legendary_t *legend = (legendary_t *)(param.this);
	static int static_block = 0;

	if (0 == static_block)
	{
		printf("Static block Legendary Animal\n");
		++static_block;
	}
	
	catCtor(param, NULL);
	printf("Legendary Ctor\n");
}

int main()
{   
    animal_t *animal = NULL;
    dog_t *dog = NULL;
    cat_t *cat = NULL;
    legendary_t *legendary = NULL;;
    cat_t *cat_color = NULL;
    wrapper_t param_animal = {0};
    wrapper_t param_dog = {0};
    wrapper_t param_cat = {0};
    wrapper_t param_legendary = {0};
    wrapper_t param_cat_color = {0};
    animal_t *array[5] = {0};
    wrapper_t wrapper_array[5] = {0};
    int i = 0;
    
    animal = (animal_t *)objectAlloc(&animal_meta);
	dog = (dog_t *)objectAlloc(&dog_meta);
	cat = (cat_t *)objectAlloc(&cat_meta);
	legendary = (legendary_t *)objectAlloc(&legendary_meta);

    param_animal.this = (object_t *)animal;
    param_dog.this = (object_t *)dog;
	param_cat.this = (object_t *)cat;
	param_legendary.this = (object_t *)legendary;
    
    animalCtor(param_animal, NULL);
   	dogCtor(param_dog);
    catCtor(param_cat, NULL);
    legendaryCtor(param_legendary);
   
   	showCounter();
   	
   	printf("%d\n", animal->ID);
	printf("%d\n", dog->animal.ID);
	printf("%d\n", cat->animal.ID);
	printf("%d\n", legendary->cat.animal.ID);
	
	free(animal), free(dog), free(cat), free(legendary);
	
	dog = (dog_t *)objectAlloc(&dog_meta);
	cat = (cat_t *)objectAlloc(&cat_meta);
	cat_color = (cat_t *)objectAlloc(&cat_meta);
	legendary = (legendary_t *)objectAlloc(&legendary_meta);
	animal = (animal_t *)objectAlloc(&animal_meta);
	
	param_dog.this = (object_t *)dog;
	param_cat.this = (object_t *)cat;
	param_cat_color.this = (object_t *)cat_color;
	param_legendary.this = (object_t *)legendary;
	param_animal.this = (object_t *)animal;
	
    dogCtor(param_dog);
    catCtor(param_cat, NULL);
    catCtor(param_cat_color, "white");
    legendaryCtor(param_legendary);
	animalCtor(param_animal, NULL);
	
 	array[0] = (animal_t *)dog;
	array[1] = (animal_t *)cat;
	array[2] = (animal_t *)cat_color;
	array[3] = (animal_t *)legendary;
	array[4] = animal;

	wrapper_array[0] = param_dog;
	wrapper_array[1] = param_cat;
	wrapper_array[2] = param_cat_color;
	wrapper_array[3] = param_legendary;
	wrapper_array[4] = param_animal;
	
	for (i = 0; i < 5; ++i)
	{
		(*array[i]->obj.metadata->class_Vtable)[SAY_HELLO](&wrapper_array[i]);
		(*array[i]->obj.metadata->class_Vtable)[NUM_MASTERS](&wrapper_array[i]);
		printf("%d\n", wrapper_array[i].num_masters);
	}
	
	for (i = 0; i < 5; ++i)
	{
		foo(array[i], wrapper_array[i]);
	}
	
	for (i = 0; i < 5; ++i)
	{
		free(array[i]);
	}
	
    return 0;
}
