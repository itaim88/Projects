
#include <stdio.h>	
#include <stdlib.h>	

#define ARRAY_SIZE 80
#define ANIMAL_NUM_MASTERS 1
#define DOG_NUM_MASTERS 2
#define ANIMAL_NUM_OF_LEGS 5
#define DOG_NUM_OF_LEGS 4


typedef void (*vfunc_t)(void *);
typedef char *(*to_string_t)(void *);
typedef int (*get_num_masters_t)(void *);

typedef enum vMetods{HASH_CODE, TO_STRING, FINALIZE, NUM_MASTERS, SAY_HELLO
                                                                } vmethods_t;

/******************* structs***********************/

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

/*******************Java2C function ******************/

void objectFinalize (object_t *this);
size_t objectHashCode (object_t *this);
char *objectToString (object_t *this);
void animalSayHello (animal_t *this);
int animalGetNumMasters (animal_t *this);
char *animalToString (animal_t *this);
void animalFinalize (animal_t *this);
void dogSayHello (dog_t *this);
void dogFinalize (dog_t *this);
char *dogToString (dog_t *this);
void catFinalize (cat_t *this);
char *catToString (cat_t *this);
void catSayHello (cat_t *this);
char *legendaryToString	(legendary_t *this);
void legendaryFinalize (legendary_t *this);
void legenderySayHello (legendary_t *this);

/************************ vfunc_tables ****************************************/

vfunc_t object_Vtable[] = {(vfunc_t)objectHashCode, (vfunc_t)objectToString,
					       (vfunc_t)objectFinalize};

vfunc_t animal_Vtable[] = {(vfunc_t)objectHashCode, (vfunc_t)animalToString,
						  (vfunc_t)animalFinalize, (vfunc_t)animalGetNumMasters,
						  (vfunc_t)animalSayHello};
							
vfunc_t dog_Vtable[] = {(vfunc_t)objectHashCode, (vfunc_t)dogToString,
					    (vfunc_t)dogFinalize, (vfunc_t)animalGetNumMasters,
						(vfunc_t)dogSayHello};
						
vfunc_t cat_Vtable[] = {(vfunc_t)objectHashCode, (vfunc_t)catToString,
				        (vfunc_t)catFinalize, (vfunc_t)animalGetNumMasters,
						(vfunc_t)animalSayHello};

vfunc_t legendary_Vtable[] = {(vfunc_t)objectHashCode, (vfunc_t)legendaryToString,
						     (vfunc_t)legendaryFinalize, (vfunc_t)animalGetNumMasters,
						     (vfunc_t)legenderySayHello};
						     
/****************** metadata ***********************************/

class_t object_meta = {"Object", sizeof(object_t), NULL, &object_Vtable};
class_t animal_meta = {"Animal", sizeof(animal_t), &object_meta, &animal_Vtable};
class_t dog_meta = {"Dog", sizeof(dog_t), &animal_meta, &dog_Vtable};
class_t cat_meta = {"Cat", sizeof(cat_t), &animal_meta, &cat_Vtable};
class_t legendary_meta = {"LegendaryAnimal", sizeof(legendary_t), &cat_meta, &legendary_Vtable};
						    	
/************************* global variables & functions*************************/

int animal_counter = 0;
char str[ARRAY_SIZE];

void animalShowCounter(){
	printf("%d\n", animal_counter);
}

void foo(animal_t *animal)
{
	char *str = ((to_string_t)((*animal->obj.metadata->class_Vtable)
	            [TO_STRING]))(animal);
	            
	printf("%s\n", str);
}

/**************** object funcs ************************************************/

size_t objectHashCode(object_t *this) 
{
	return (size_t)this;
}

char *objectToString(object_t *this)
{
	sprintf(str, "%s@%lu", this->metadata->name, (size_t)objectHashCode(this));
	
	return str;
}

void objectFinalize(object_t *this) 
{
	free(this);
}

/************************** Object create *************************************/

object_t *objectAlloc(class_t *class)
{
	object_t *obj = (object_t *)malloc(class->size);
	obj->metadata = class;
	
	return obj;
}
/*************************Animal **********************************************/

void animalCtor(animal_t *this, int *num_masters)
{
	static int static_block = 0;
	char *str = NULL;
	
	if (0 == static_block)
	{
		printf("Static block Animal 1\n");
		printf("Static block Animal 2\n");
		++static_block;
	}
	
	{
		printf("Instance initialization block Animal\n");
	}
	
	this->ID = ++animal_counter;
	this->num_legs = ANIMAL_NUM_OF_LEGS;
	
	if (num_masters == NULL)
	{
		printf("Animal Ctor\n");
		this->num_masters = ANIMAL_NUM_MASTERS;
		(*this->obj.metadata->class_Vtable)[SAY_HELLO](this);
		animalShowCounter(NULL);
		str = ((to_string_t)((*this->obj.metadata->class_Vtable)[TO_STRING]))(this);
		printf ("%s\n", str);
		str = objectToString((object_t *)this);
		printf("%s\n", str);
	}
	
	else 
	{
		printf("Animal Ctor int\n");
		this->num_masters = *num_masters;
	}
}

void animalSayHello(animal_t *this)
{
	printf("Animal Hello!\n");
	printf("I have %d legs\n", this->num_legs);
}

int animalGetNumMasters(animal_t *this)
{
	return this->num_masters;
}

char *animalToString(animal_t *this)
{
	sprintf(str, "Animal with ID: %d", this->ID);

	return str;
}

void animalFinalize(animal_t *this) 
{
	printf("finalize Animal with ID: %d\n", this->ID);
	objectFinalize((object_t *)this);
}

/***************************Dog******************************/

void dogCtor(dog_t *this)
{
	int dog_num_masters = DOG_NUM_MASTERS;
	static int static_block = 0;
	
	if(0 == static_block)
	{
		printf("Static block Dog\n");
		++static_block;
	}

	animalCtor((animal_t *)this, &dog_num_masters);
	
	{
		printf("Instance initialization block Dog\n");
	}

	printf("Dog Ctor\n");
	
	this->num_legs = DOG_NUM_OF_LEGS;
}

void dogSayHello(dog_t *this)
{
	printf("Dog Hello!\n");
	printf("I have %d legs\n", this->num_legs);
}

char *dogToString(dog_t *this)
{	
	sprintf(str, "Dog with ID: %d", this->animal.ID);
	
	return str;
}

void dogFinalize(dog_t *this) 
{
	printf("finalize Dog with ID: %d\n", ((animal_t *)this)->ID);
	objectFinalize((object_t *)this);
}

/*************************Cat***************************/

void catCtor(cat_t *this, char *colors)
{
	static int static_block = 0;

	this->num_masters = 5;
	
	if (0 == static_block)
	{
		printf("Static block Cat\n");
		++static_block;
	}
	
	if (colors == NULL)
	{
		catCtor(this, "black");
		this->num_masters = 2;
		printf("Cat Ctor\n");
	}
	
	else
	{
		animalCtor((animal_t *)this, NULL);
		
		this->colors = colors;
		printf("Cat Ctor with color: %s\n", colors);
	}
}

char *catToString(cat_t *this)
{	
	sprintf(str, "Cat with ID: %d", this->animal.ID);
	 
	return str;
}

void catFinalize(cat_t *this) 
{
	printf("finalize Cat with ID: %d\n", ((animal_t *)this)->ID);
	objectFinalize((object_t *)this);
}

/************************ LegendaryAnimal *************************************/

void legendaryCtor(legendary_t *this)
{
	static int static_block = 0;

	if (0 == static_block)
	{
		printf("Static block Legendary Animal\n");
		++static_block;
	}
	
	catCtor((cat_t *)this, NULL);
	
	printf("Legendary Ctor\n");
}

char *legendaryToString(legendary_t *this)
{	
	sprintf(str, "LegendaryAnimal with ID: %d", 
			((animal_t *)this)->ID);
			
	return str;
}

void legenderySayHello(legendary_t *this)
{
	(this);
	
	printf("Legendary Hello!\n");
}

void legendaryFinalize(legendary_t *this) 
{
	printf("finalize LegendaryAnimal with ID: %d\n",((animal_t *)this)->ID);
	objectFinalize((object_t *)this);
}

int main()
{   
    animal_t *animal = (animal_t *)objectAlloc(&animal_meta);
	dog_t *dog = (dog_t *)objectAlloc(&dog_meta);
	cat_t *cat = (cat_t *)objectAlloc(&cat_meta);
	legendary_t *legendary = (legendary_t *)objectAlloc(&legendary_meta);
	cat_t *cat_color = NULL;
	animal_t *animals_array[5] = {0};
    int i = 0;
    animalCtor(animal, NULL);
   	dogCtor(dog);
    catCtor(cat, NULL);
    legendaryCtor(legendary);
   
   	animalShowCounter();
   	
   	printf("%d\n", ((animal_t *)animal)->ID);
	printf("%d\n", ((dog_t *)dog)->animal.ID);
	printf("%d\n", ((cat_t *)cat)->animal.ID);
	printf("%d\n", ((legendary_t *)legendary)->cat.animal.ID);
	
    free(animal), free(dog), free(cat), free(legendary);
	
	dog = (dog_t *)objectAlloc(&dog_meta);
	cat = (cat_t *)objectAlloc(&cat_meta);
	cat_color = (cat_t *)objectAlloc(&cat_meta);
	legendary = (legendary_t *)objectAlloc(&legendary_meta);
	animal = (animal_t *)objectAlloc(&animal_meta);
	
    dogCtor(dog);
    catCtor(cat, NULL);
    catCtor(cat_color, "white");
    legendaryCtor(legendary);
	animalCtor(animal, NULL);
	
 	animals_array[0] = (animal_t *)dog;
	animals_array[1] = (animal_t *)cat;
	animals_array[2] = (animal_t *)cat_color;
	animals_array[3] = (animal_t *)legendary;
	animals_array[4] = (animal_t *)animal;
	
	for (i = 0; i < 5; ++i)
	{
		(*animals_array[i]->obj.metadata->class_Vtable)[SAY_HELLO](animals_array[i]);
		printf("%d\n", ((get_num_masters_t)
			((*animals_array[i]->obj.metadata->class_Vtable)[NUM_MASTERS]))(animals_array[i]));
	}
	
	for (i = 0; i < 5; ++i)
	{
		foo(animals_array[i]);
	}
	
	for (i = 0; i < 5; ++i)
	{
		(*animals_array[i]->obj.metadata->class_Vtable)[FINALIZE](animals_array[i]);
	}
	
    return 0;
}
