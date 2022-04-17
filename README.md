div id="header" align="center">
  <h1>
    Philosophers
  </h1>
  <p>I never thought philosophy would be so deadly</p>
</div>

### Table of contents
- [About philosophers](#about-philosophers)
- [Mandatory part](#mandatory-part)
- [Bonus part](#bonus-part)
- [How to run the simulation](#how-to-run-the-simulation)

## About philosophers
This project simulates **the dining philosophers problem** that states that N philosophers seated around a circular table with a large bowl of spaghetti in the middle of the table. A philosopher may eat if he can pick up the two chopsticks on in each hand. The philosophers alternatively **eat**, **think**, or **sleep**. While they are eating, they are not thinking nor sleeping; while thinking, they are not eating nor sleeping; and, of course, while sleeping, they are not eating nor thinking. When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.

## Mandatory part
- Each philosopher is a thread.
- There is one fork between each pair of philosophers. Therefore, if there are several
philosophers, each philosopher has a fork on their left side and a fork on their right
side.
- Forks states are protected from duplicating with a mutex for each of them.

## Bonus part
- Each philosopher is a process.
- All the forks are put in the middle of the table.
- They have no states in memory but the number of available forks is represented by
a semaphore.

## How to run the simulation
1. Clone this repo and go to the cloned directoty
``` sh
https://github.com/cvine21/Philosophers.git
cd Philosophers/
```
2. Run Makefile for the mandatory part:
``` sh
cd philo && make
```
for the bonus part:
``` sh
cd philo_bonus && make bonus
```
3. Run simulation

Program should take the following arguments:

**number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]**
- number_of_philosophers: The number of philosophers and also the number
of forks.
- time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
- time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.
- time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
- number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simula

Some cases of mandatory part simulation:
./philo 5   800 200 200		     	# should live
./philo 5   800 200 200 7       # everyone should eat at least 7 times



