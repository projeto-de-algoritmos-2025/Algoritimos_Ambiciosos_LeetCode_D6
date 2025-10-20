#include <vector>
#include <limits>
#include <iostream>

class Solution {
public:
    bool increasingTriplet(std::vector<int>& nums) {
        
        int primeiro = std::numeric_limits<int>::max();
        int segundo = std::numeric_limits<int>::max();

        // Esta lógica falha. Ela não atualiza 'primeiro' para um
        // candidato melhor depois que 'segundo' já foi encontrado.
        for (int num : nums) {
            
            if (num > segundo) {
                return true;
            } 
            
            // A ordem aqui está trocada, e a lógica é diferente
            if (num > primeiro) {
                segundo = num;
            } else {
                primeiro = num;
            }
        }
        
        return false;
    }
};