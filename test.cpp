#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


















































class Character {
public:
    string name;
    int hp;
    int attack;

    Character(string n, int h, int a)
        : name(n), hp(h), attack(a) {}

    bool isAlive() {
        return hp > 0;
    }
};

int randomDamage(int maxAttack) {
    return rand() % maxAttack + 1;
}

void showStatus(const Character& player, const Character& enemy) {
    cout << "\n===== STATUS =====\n";
    cout << player.name << " HP: " << player.hp << endl;
    cout << enemy.name << " HP: " << enemy.hp << endl;
    cout << "==================\n";
}

void showStatus(const Character& player, const Character& enemy) {
    cout << "\n===== STATUS =====\n";
    cout << jin << " HP: " << player.hp << endl;
    cout << riku << " HP: " << enemy.hp << endl;
    cout << "==================\n";
}

int main() {

    srand(static_cast<unsigned int>(time(nullptr)));
    
    Character player("kosei", 100, 20);
    Character enemy("Goblin", 80, 15);

    cout << "=== Mini Battle Game ===\n";

    while (player.isAlive() && enemy.isAlive()) {

        showStatus(player, enemy);

        cout << "\n1. Attack\n";
        cout << "2. Heal\n";
        cout << "Select: ";

        int choice;
        cin >> choice;

        // Player turn
        if (choice == 1) {

            int damage = randomDamage(player.attack);

            enemy.hp -= damage;

            cout << "\nYou attacked!\n";
            cout << "Damage: " << damage << endl;

        } else if (choice == 2) {

            int heal = rand() % 15 + 5;

            player.hp += heal;

            if (player.hp > 100)
                player.hp = 100;

            cout << "\nYou healed " << heal << " HP!\n";

        } else {

            cout << "\nInvalid command.\n";
            continue;
        }

        // Enemy defeated
        if (!enemy.isAlive()) {
            cout << "\nYou win!\n";
            break;
        }

        // Enemy turn
        int enemyDamage = randomDamage(enemy.attack);

        player.hp -= enemyDamage;

        cout << "\nEnemy attacks!\n";
        cout << "You took " << enemyDamage << " damage.\n";

        // Player defeated
        if (!player.isAlive()) {
            cout << "\nGame Over...\n";
            break;
        }
    }

    cout << "\nThanks for playing!\n";

    return 0;
}