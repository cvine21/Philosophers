<div id="header" align="center">
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
- There is one fork between each pair of philosophers. Therefore, if there are several philosophers, each philosopher has a fork on their left side and a fork on their right side.
- Forks states are protected from duplicating with a mutex for each of them.

## Bonus part
- Each philosopher is a process.
- All the forks are put in the middle of the table.
- They have no states in memory but the number of available forks is represented by a semaphore.

## How to run the simulation
1. Clone this repo and go to the cloned directoty
``` sh
https://github.com/cvine21/philosophers.git

cd philosophers/
```
2. Run the simulation for the mandatory part:
``` sh
cd philo && make

./philo [arg1] [arg2] [arg3] [arg4] [arg5]
```
bonus part:
``` sh
cd philo_bonus && make bonus

./philo_bonus [arg1] [arg2] [arg3] [arg4] [arg5]
```
- arg1: The number of philosophers and also the number of forks.
- arg2: If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
- arg3: The time it takes for a philosopher to eat (in milliseconds). During that time, they will need to hold two forks.
- arg4: The time a philosopher will spend sleeping (in milliseconds).
- arg5 (optional argument): If all philosophers have eaten number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.

Some cases for the mandatory part:
```
./philo 1 800 200 200     - the philosopher should not eat and should die.
./philo 5 800 200 200     - no one should die.
./philo 5 800 200 200 7   - no one should die and the simulation should stop when all the philospher everyone has eaten 7 times.
./philo 4 410 200 200     - no one should die.
./philo 4 310 200 100     - a philosopher should die.
```
bonus part:
```
./philo_bonus 1 800 200 200     - the philosopher should not eat and should die.
./philo_bonus 5 800 200 200     - no one should die.
./philo_bonus 5 800 200 200 7   - no one should die and the simulation should stop when all the philospher everyone has eaten 7 times.
./philo_bonus 4 410 200 200     - no one should die.
./philo_bonus 4 310 200 100     - a philosopher should die.
```
