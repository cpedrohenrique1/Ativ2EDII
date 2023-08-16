#ifndef CONJUNTO_H
#define CONJUNTO_H
#include <QString>

namespace Pedro{
class Conjunto
{
private:
    int tamanho;
    int *array;
public:
    Conjunto(int tamanho);
    QString getConjunto() const;
    ~Conjunto();
    QString buscarValor(int valor);
};
}

#endif // CONJUNTO_H
