#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "Brain.hpp"

static void printTitle(const std::string &title)
{
	std::cout << "\n===== " << title << " =====" << std::endl;
}

int main()
{
	printTitle("Testing Brain Ownership");
	
	// Create animals with brains
	const Animal* dog1 = new Dog();
	Dog* dog2 = new Dog();
	const Animal* cat1 = new Cat();
	
	printTitle("Adding ideas to Dog 1");
	dog1->setIdea("Woof woof!");
	dog1->setIdea("Play fetch!");
	dog1->setIdea("Squirrel!");
	std::cout << "Dog 1 idea:\n" << dog1->getIdea() << std::endl;
	
	printTitle("Adding ideas to Dog 2");
	dog2->setIdea("Bark bark!");
	dog2->setIdea("Eat treats!");
	std::cout << "Dog 2 idea:\n" << dog2->getIdea() << std::endl;
	
	printTitle("Adding ideas to Cat 1");
	std::cout << "Cat overthinks more than 100 ideas:\n" << std::endl;
	cat1->setIdea("Meow!");
	cat1->setIdea("Chase mouse!");
	cat1->setIdea("Nap time!");
	cat1->setIdea("Chasing a red laser dot");
	cat1->setIdea("Staring at a wall like it knows something");
	cat1->setIdea("Knocking a glass off the table");
	cat1->setIdea("Sleeping in a cardboard box");
	cat1->setIdea("Watching birds through the window");
	cat1->setIdea("Plotting world domination");
	cat1->setIdea("Demanding food at 3 AM");
	cat1->setIdea("Ignoring the expensive cat bed");
	cat1->setIdea("Squeezing into a tiny jar");
	cat1->setIdea("Attacking a moving shoelace");
	cat1->setIdea("Sitting on a laptop keyboard");
	cat1->setIdea("Guarding the food bowl");
	cat1->setIdea("Hiding inside a laundry basket");
	cat1->setIdea("Staring at its own reflection");
	cat1->setIdea("Running wildly at midnight");
	cat1->setIdea("Watching invisible ghosts");
	cat1->setIdea("Sleeping on warm laundry");
	cat1->setIdea("Trying to catch a fly");
	cat1->setIdea("Judging everyone silently");
	cat1->setIdea("Curling up in a sunbeam");
	cat1->setIdea("Pushing pens off the desk");
	cat1->setIdea("Stealing a sock");
	cat1->setIdea("Ambushing from behind the couch");
	cat1->setIdea("Climbing the curtains");
	cat1->setIdea("Inspecting grocery bags");
	cat1->setIdea("Rolling dramatically on the floor");
	cat1->setIdea("Watching fish in an aquarium");
	cat1->setIdea("Pretending not to hear its name");
	cat1->setIdea("Hunting a dust particle");
	cat1->setIdea("Sleeping on the owner's face");
	cat1->setIdea("Exploring inside a backpack");
	cat1->setIdea("Guarding a random cardboard box");
	cat1->setIdea("Listening to mysterious noises");
	cat1->setIdea("Chewing on a plant leaf");
	cat1->setIdea("Watching rain through the window");
	cat1->setIdea("Stepping on a keyboard mid-typing");
	cat1->setIdea("Stealing a warm seat");
	cat1->setIdea("Investigating a new smell");
	cat1->setIdea("Catching imaginary prey");
	cat1->setIdea("Knocking over a pencil cup");
	cat1->setIdea("Peeking from behind a door");
	cat1->setIdea("Testing gravity on small objects");
	cat1->setIdea("Sleeping inside a suitcase");
	cat1->setIdea("Sneaking into a closet");
	cat1->setIdea("Following the owner everywhere");
	cat1->setIdea("Watching TV intensely");
	cat1->setIdea("Fighting a blanket lump");
	cat1->setIdea("Waiting for the treat bag sound");
	cat1->setIdea("Sitting like a loaf");
	cat1->setIdea("Yawning dramatically");
	cat1->setIdea("Stretching after a long nap");
	cat1->setIdea("Watching the ceiling fan");
	cat1->setIdea("Inspecting a delivery box");
	cat1->setIdea("Listening to birds outside");
	cat1->setIdea("Trying to fit into a mug");
	cat1->setIdea("Jumping onto the highest shelf");
	cat1->setIdea("Guarding a toy mouse");
	cat1->setIdea("Peeking out of a paper bag");
	cat1->setIdea("Sitting inside a sink");
	cat1->setIdea("Watching a bug crawl");
	cat1->setIdea("Rolling in catnip");
	cat1->setIdea("Hiding under the bed");
	cat1->setIdea("Sneaking onto the kitchen counter");
	cat1->setIdea("Testing a new scratching post");
	cat1->setIdea("Watching people from the window");
	cat1->setIdea("Trying to open a cabinet");
	cat1->setIdea("Listening to a distant noise");
	cat1->setIdea("Stealing a piece of string");
	cat1->setIdea("Pretending to hunt a shadow");
	cat1->setIdea("Sleeping like a fluffy donut");
	cat1->setIdea("Staring into the void");
	cat1->setIdea("Guarding a sunny spot");
	cat1->setIdea("Playing with a bottle cap");
	cat1->setIdea("Waiting beside the food bowl");
	cat1->setIdea("Sneaking behind a curtain");
	cat1->setIdea("Attacking a paper ball");
	cat1->setIdea("Watching the door patiently");
	cat1->setIdea("Exploring a new room");
	cat1->setIdea("Climbing onto the fridge");
	cat1->setIdea("Balancing on a narrow ledge");
	cat1->setIdea("Hunting a bouncing light reflection");
	cat1->setIdea("Curled up like a croissant");
	cat1->setIdea("Guarding the sofa throne");
	cat1->setIdea("Looking offended for no reason");
	cat1->setIdea("Watching the washing machine");
	cat1->setIdea("Following a drifting feather");
	cat1->setIdea("Hiding in a shoebox");
	cat1->setIdea("Poking a sleeping dog");
	cat1->setIdea("Listening to the refrigerator hum");
	cat1->setIdea("Trying to catch falling leaves");
	cat1->setIdea("Rolling off the couch accidentally");
	cat1->setIdea("Waiting dramatically for dinner");
	cat1->setIdea("Sleeping with one eye open");
	cat1->setIdea("Inspecting a cup of water");
	cat1->setIdea("Jumping at a sudden noise");
	cat1->setIdea("Watching shadows move");
	cat1->setIdea("Guarding the hallway");
	cat1->setIdea("Poking a sleeping dog");
	cat1->setIdea("Listening to the refrigerator hum");
	cat1->setIdea("Trying to catch falling leaves");
	cat1->setIdea("Rolling off the couch accidentally");
	cat1->setIdea("Waiting dramatically for dinner");
	cat1->setIdea("Sleeping with one eye open");
	cat1->setIdea("Inspecting a cup of water");
	cat1->setIdea("Jumping at a sudden noise");
	cat1->setIdea("Watching shadows move");
	cat1->setIdea("Guarding the hallway");

	
	printTitle("Verifying separate brains");
	std::cout << "\nDog 1 idea again: \n" << dog1->getIdea() << std::endl;
	std::cout << "\nDog 2 idea again: \n" << dog2->getIdea() << std::endl;
	std::cout << "\nCat 1 idea:\n" << cat1->getIdea() << std::endl;
	std::cout << "\n";

	printTitle("Verifying copies");
	const Animal* originalCat = cat1;  // save Cat before reassigning pointer
	cat1 = dog1;
	std::cout << "\nNew Cat 1 ideas are:\n" << cat1->getIdea() << std::endl;

	printTitle(" TEST FINISHED ");
	std::cout << "\n" << std::endl;
	// Clean up — cat1 and dog1 now point to the same Dog, delete it only once
	delete originalCat;
	delete dog1;
	delete dog2;

	printTitle("Subject required animal array test");

	const int animalCount = 10;
	Animal *animals[animalCount];

	for (int i = 0; i < animalCount / 2; i++)
		animals[i] = new Dog();
	for (int i = animalCount / 2; i < animalCount; i++)
		animals[i] = new Cat();

	for (int i = 0; i < animalCount; i++)
		delete animals[i];


	// Dog basic;
	// {
	// 	Dog tmp = basic;
	// }

	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// delete j;//should not create a leak
	// delete i;

	return 0;
}