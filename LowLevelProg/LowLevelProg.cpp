// LowLevelProg.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <xmmintrin.h>
#include <AssemblyMath.h>
#include <CustomMath.h>

using namespace Mmath;
using namespace CMath;

void FloatTests()
{
    std::cout << "Starting inv test" << std::endl;
    float one = 2.4f;
    float two = -2.4f;
    float three = -125.685f;
    float four = 800125421.f;
    float five = -0.0124538521f;

    std::cout << one << " becomes " << Mmath::AssemblyMath::AInv(one) << std::endl;
    std::cout << two << " becomes " << Mmath::AssemblyMath::AInv(two) << std::endl;
    std::cout << three << " becomes " << Mmath::AssemblyMath::AInv(three) << std::endl;
    std::cout << four << " becomes " << Mmath::AssemblyMath::AInv(four) << std::endl;
    std::cout << five << " becomes " << Mmath::AssemblyMath::AInv(five) << std::endl;

    std::cout << std::endl;

    std::cout << "Starting Abs test" << std::endl;

    std::cout << one << " becomes " << Mmath::AssemblyMath::AAbs(one) << std::endl;
    std::cout << two << " becomes " << Mmath::AssemblyMath::AAbs(two) << std::endl;
    std::cout << three << " becomes " << Mmath::AssemblyMath::AAbs(three) << std::endl;
    std::cout << four << " becomes " << Mmath::AssemblyMath::AAbs(four) << std::endl;
    std::cout << five << " becomes " << Mmath::AssemblyMath::AAbs(five) << std::endl;

    std::cout << std::endl;
}

void Vec2Tests()
{
    std::cout << "Starting Operator+ test" << std::endl;

    AVector2 A = AVector2(12.51f, -45.66f);
    AVector2 B = AVector2(-74.f, 33.f);
    AVector2 C = AVector2(-25.23f, -78.12);
    AVector2 D = AVector2(45.f, 2.66f);
    AVector2 E = AVector2(-1.f, 8.25f);
    AVector2 F = AVector2(8.f, 0.f);

    std::cout << A << "+" << B << " becomes " << A + B << std::endl;
    std::cout << C << "+" << D << " becomes " << C + D << std::endl;
    std::cout << E << "+" << F << " becomes " << E + F << std::endl;

    std::cout << std::endl << "Starting Operator- test" << std::endl;
    std::cout << A << "-" << B << " becomes " << A - B << std::endl;
    std::cout << C << "-" << D << " becomes " << C - D << std::endl;
    std::cout << E << "-" << F << " becomes " << E - F << std::endl;

    std::cout << std::endl << "Starting Operator+= test" << std::endl;
    std::cout << A << "+=" << B << " becomes ";
    A += B;
    std::cout << A << std::endl;

    std::cout << C << "+=" << D << " becomes ";
    C += D;
    std::cout << C << std::endl;

    std::cout << E << "+=" << F << " becomes ";
    E += F;
    std::cout << E << std::endl;

    std::cout << std::endl << "Starting Operator-= test" << std::endl;
    std::cout << A << "-=" << B << " becomes ";
    A -= B;
    std::cout << A << std::endl;

    std::cout << C << "-=" << D << " becomes ";
    C -= D;
    std::cout << C << std::endl;

    std::cout << E << "-=" << F << " becomes ";
    E -= F;
    std::cout << E << std::endl;

    std::cout << std::endl << "Starting -operator test" << std::endl;
    std::cout << A << " becomes " << -A << " and is still " << A << std::endl;
    std::cout << B << " becomes " << -B << " and is still " << B << std::endl;
    std::cout << C << " becomes " << -C << " and is still " << C << std::endl;
    std::cout << D << " becomes " << -D << " and is still " << D << std::endl;
    std::cout << E << " becomes " << -E << " and is still " << E << std::endl;
    std::cout << F << " becomes " << -F << " and is still " << F << std::endl;

    AVector2 G;
    AVector2 H;
    AVector2 I;

    std::cout << std::endl << "Starting Operator= test" << std::endl;
    std::cout << G << "=" << A << " becomes ";
    G = A;
    std::cout << G << std::endl;

    std::cout << H << "=" << B << " becomes ";
    H = B;
    std::cout << B << std::endl;

    std::cout << I << "=" << C << " becomes ";
    I = C;
    std::cout << I << std::endl;

    std::cout << std::endl << "Starting DotProduct test" << std::endl;
    Vector2 Abis = Vector2(A.x,A.y);
    Vector2 Bbis = Vector2(B.x, B.y);
    std::cout << "Creating Abis and Bbis vector from " << A << " and " << B << std::endl;
    std::cout << "Abis=" << Abis << " and Bbis=" << Bbis << std::endl;
    std::cout << Abis << "DOT" << Bbis << " becomes " << Abis.DotProduct(Bbis)<< std::endl;
    std::cout << A << "DOT" << B << " becomes " << A.DotProduct(B) << std::endl;
}


int main()
{
    FloatTests();

    std::cout << "________________________AVEC2________________________" << std::endl;
    Vec2Tests();

    int x = 1054;
    x += x;
    return x;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
