// LowLevelProg.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ratio>
#include <chrono>
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

void Vec2PerfTests()
{
    std::cout << std::endl << "###PERF TESTS###" << std::endl;

    int nbOfTests = INT64_MAX;
    const int size = 225;

    Vector2 ClassicVecs[size][size];
    AVector2 MMVecs[size][size];

    std::srand(std::time(nullptr));

    //Vector Init
    std::cout << std::endl << "Vec2 init" << std::endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            float max = 100.0f;
            float min = -100.0f;

            float cX = min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(max - min)));
            float cY = min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(max - min)));
            float mX = min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(max - min)));
            float mY = min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(max - min)));

            ClassicVecs[i][j] = Vector2(cX,cY);
            MMVecs[i][j] = AVector2(mX,mY);
        }
    }

    

    typedef std::chrono::steady_clock::time_point timePoint;

    std::cout << std::endl << "Addition" << std::endl;
    Vector2 result;

    std::cout << "Classic" << std::endl << std::endl;
    timePoint start = std::chrono::high_resolution_clock::now();
    for (int testNb = 0; testNb < nbOfTests; testNb++)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                result = ClassicVecs[i][j] + ClassicVecs[i][j];
            }
        }
    }
    timePoint end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "computation took: " << elapsed_seconds.count() << "s" << std::endl;

    std::cout << "MM" << std::endl << std::endl;
    AVector2 mResult;

    start = std::chrono::high_resolution_clock::now();
    for (int testNb = 0; testNb < nbOfTests; testNb++)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                mResult = MMVecs[i][j] + MMVecs[i][j];
            }
        }
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "computation took: " << elapsed_seconds.count() << "s" << std::endl;
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

    Vector2 Abis = Vector2(A.x, A.y);
    Vector2 Bbis = Vector2(B.x, B.y);
    Vector2 Cbis = Vector2(C.x, C.y);
    Vector2 Dbis = Vector2(D.x, D.y);
    Vector2 Ebis = Vector2(E.x, E.y);
    Vector2 Fbis = Vector2(F.x, F.y);
    Vector2 Gbis = Vector2(G.x, G.y);
    Vector2 Hbis = Vector2(H.x, H.y);

    std::cout << std::endl << "Creating normal vectors from MM vectors" << std::endl;
    std::cout << "Abis=" << Abis << " and Bbis=" << Bbis << std::endl;
    std::cout << "Cbis=" << Cbis << " and Dbis=" << Dbis << std::endl;
    std::cout << "Ebis=" << Ebis << " and Fbis=" << Fbis << std::endl;
    std::cout << "Gbis=" << Gbis << " and Hbis=" << Hbis << std::endl;



    std::cout << std::endl << "Starting mul test" << std::endl;

    std::cout << "MM vectors" << std::endl;
    std::cout << A << "*" << B << " becomes " << A * B << std::endl;
    std::cout << C << "*" << D << " becomes " << C * D << std::endl;
    std::cout << E << "*" << F << " becomes " << E * F << std::endl;
    std::cout << G << "*" << H << " becomes " << G * H << std::endl;

    std::cout << "Classic vectors" << std::endl;
    std::cout << Abis << "*" << Bbis << " becomes " << Abis * Bbis << std::endl;
    std::cout << Cbis << "*" << Dbis << " becomes " << Cbis * Dbis << std::endl;
    std::cout << Ebis << "*" << Fbis << " becomes " << Ebis * Fbis << std::endl;
    std::cout << Gbis << "*" << Hbis << " becomes " << Gbis * Hbis << std::endl;

    std::cout << "MM vectors" << std::endl;
    std::cout << A << "*=" << B << " becomes ";
    A *= B;
    std::cout << A << std::endl;

    std::cout << C << "*=" << D << " becomes ";
    C *= D;
    std::cout << C << std::endl;

    std::cout << E << "*=" << F << " becomes ";
    E *= F;
    std::cout << E << std::endl;

    std::cout << G << "*=" << H << " becomes ";
    G *= H;
    std::cout << G << std::endl;

    std::cout << "Classic vectors" << std::endl;
    std::cout << Abis << "*=" << Bbis << " becomes ";
    Abis *= Bbis;
    std::cout << Abis << std::endl;

    std::cout << Cbis << "*=" << Dbis << " becomes ";
    Cbis *= Dbis;
    std::cout << Cbis << std::endl;

    std::cout << Ebis << "*=" << Fbis << " becomes ";
    Ebis *= Fbis;
    std::cout << Ebis << std::endl;

    std::cout << Gbis << "*=" << Hbis << " becomes ";
    Gbis *= Hbis;
    std::cout << Gbis << std::endl;



    std::cout << std::endl << "Starting DotProduct test" << std::endl;

    std::cout << Abis << "DOT" << Bbis << " becomes " << Abis.DotProduct(Bbis)<< std::endl;
    std::cout << A << "DOT" << B << " becomes " << A.DotProduct(B) << std::endl;
    std::cout << Cbis << "DOT" << Dbis << " becomes " << Cbis.DotProduct(Dbis) << std::endl;
    std::cout << C << "DOT" << D << " becomes " << C.DotProduct(D) << std::endl;
    std::cout << Ebis << "DOT" << Fbis << " becomes " << Ebis.DotProduct(Fbis) << std::endl;
    std::cout << E << "DOT" << F << " becomes " << E.DotProduct(F) << std::endl;
    std::cout << Gbis << "DOT" << Hbis << " becomes " << Gbis.DotProduct(Hbis) << std::endl;
    std::cout << G << "DOT" << H << " becomes " << G.DotProduct(H) << std::endl;

    std::cout << Abis << "STATIC DOT" << Bbis << " becomes " << Vector2::DotProduct(Abis,Bbis) << std::endl;
    std::cout << A << "STATIC DOT" << B << " becomes " << AVector2::DotProduct(A,B) << std::endl;
    std::cout << Cbis << "STATIC DOT" << Dbis << " becomes " << Vector2::DotProduct(Cbis,Dbis) << std::endl;
    std::cout << C << "STATIC DOT" << D << " becomes " << AVector2::DotProduct(C,D) << std::endl;
    std::cout << Ebis << "STATIC DOT" << Fbis << " becomes " << Vector2::DotProduct(Ebis,Fbis) << std::endl;
    std::cout << E << "STATIC DOT" << F << " becomes " << AVector2::DotProduct(E,F) << std::endl;
    std::cout << Gbis << "STATIC DOT" << Hbis << " becomes " << Vector2::DotProduct(Gbis,Hbis) << std::endl;
    std::cout << G << "STATIC DOT" << H << " becomes " << AVector2::DotProduct(G,H) << std::endl;

    
    
    std::cout << std::endl << "Starting Magnitude test" << std::endl;

    std::cout << Abis << " magnitude is " << Abis.GetMagnitude() << std::endl;
    std::cout << A << " magnitude is " << A.GetMagnitude() << std::endl;
    std::cout << Bbis << " magnitude is " << Bbis.GetMagnitude() << std::endl;
    std::cout << B << " magnitude is " << B.GetMagnitude() << std::endl;
    std::cout << Cbis << " magnitude is "<< Cbis.GetMagnitude() << std::endl;
    std::cout << C << " magnitude is " << C.GetMagnitude() << std::endl;
    std::cout << Dbis << " magnitude is " <<Dbis.GetMagnitude() << std::endl;
    std::cout << D << " magnitude is " << D.GetMagnitude() << std::endl;
    std::cout << Ebis << " magnitude is " <<Ebis.GetMagnitude() << std::endl;
    std::cout << E << " magnitude is " << E.GetMagnitude() << std::endl;
    std::cout << Fbis << " magnitude is " << Fbis.GetMagnitude() << std::endl;
    std::cout << F << " magnitude is " << F.GetMagnitude() << std::endl;
    std::cout << Gbis << " magnitude is " <<Gbis.GetMagnitude() << std::endl;
    std::cout << G << " magnitude is " << G.GetMagnitude() << std::endl;
    std::cout << Hbis << " magnitude is " << Hbis.GetMagnitude() << std::endl;
    std::cout << H << " magnitude is " << H.GetMagnitude() << std::endl;


    
    std::cout << std::endl << "Starting Square Magnitude test" << std::endl;

    std::cout << Abis << " SquareMagnitude is " << Abis.GetSquareMagnitude() << std::endl;
    std::cout << A << " SquareMagnitude is " << A.GetSquareMagnitude() << std::endl;
    std::cout << Bbis << " SquareMagnitude is " << Bbis.GetSquareMagnitude() << std::endl;
    std::cout << B << " SquareMagnitude is " << B.GetSquareMagnitude() << std::endl;
    std::cout << Cbis << " SquareMagnitude is " << Cbis.GetSquareMagnitude() << std::endl;
    std::cout << C << " SquareMagnitude is " << C.GetSquareMagnitude() << std::endl;
    std::cout << Dbis << " SquareMagnitude is " << Dbis.GetSquareMagnitude() << std::endl;
    std::cout << D << " SquareMagnitude is " << D.GetSquareMagnitude() << std::endl;
    std::cout << Ebis << " SquareMagnitude is " << Ebis.GetSquareMagnitude() << std::endl;
    std::cout << E << " SquareMagnitude is " << E.GetSquareMagnitude() << std::endl;
    std::cout << Fbis << " SquareMagnitude is " << Fbis.GetSquareMagnitude() << std::endl;
    std::cout << F << " SquareMagnitude is " << F.GetSquareMagnitude() << std::endl;
    std::cout << Gbis << " SquareMagnitude is " << Gbis.GetSquareMagnitude() << std::endl;
    std::cout << G << " SquareMagnitude is " << G.GetSquareMagnitude() << std::endl;
    std::cout << Hbis << " SquareMagnitude is " << Hbis.GetSquareMagnitude() << std::endl;
    std::cout << H << " SquareMagnitude is " << H.GetSquareMagnitude() << std::endl;

    
    std::cout << std::endl << "Starting Distance test" << std::endl;

    std::cout << Abis << " dist " << Bbis << " becomes " << Abis.GetDistance(Bbis) << std::endl;
    std::cout << A << " dist " << B << " becomes " << A.GetDistance(B) << std::endl;
    std::cout << Cbis << " dist " << Dbis << " becomes " << Cbis.GetDistance(Dbis) << std::endl;
    std::cout << C << " dist " << D << " becomes " << C.GetDistance(D) << std::endl;
    std::cout << Ebis << " dist " << Fbis << " becomes " << Ebis.GetDistance(Fbis) << std::endl;
    std::cout << E << " dist " << F << " becomes " << E.GetDistance(F) << std::endl;
    std::cout << Gbis << " dist " << Hbis << " becomes " << Gbis.GetDistance(Hbis) << std::endl;
    std::cout << G << " dist " << H << " becomes " << G.GetDistance(H) << std::endl;

    std::cout << Abis << "STATIC DIST" << Bbis << " becomes " << Vector2::GetDistance(Abis, Bbis) << std::endl;
    std::cout << A << "STATIC DIST" << B << " becomes " << AVector2::GetDistance(A, B) << std::endl;
    std::cout << Cbis << "STATIC DIST" << Dbis << " becomes " << Vector2::GetDistance(Cbis, Dbis) << std::endl;
    std::cout << C << "STATIC DIST" << D << " becomes " << AVector2::GetDistance(C, D) << std::endl;
    std::cout << Ebis << "STATIC DIST" << Fbis << " becomes " << Vector2::GetDistance(Ebis, Fbis) << std::endl;
    std::cout << E << "STATIC DIST" << F << " becomes " << AVector2::GetDistance(E, F) << std::endl;
    std::cout << Gbis << "STATIC DIST" << Hbis << " becomes " << Vector2::GetDistance(Gbis, Hbis) << std::endl;
    std::cout << G << "STATIC DIST" << H << " becomes " << AVector2::GetDistance(G, H) << std::endl;

    
    std::cout << std::endl << "Starting Normal test" << std::endl;

    std::cout << Abis << " normal is " << Abis.GetNormalized() << std::endl;
    std::cout << A << " normal is " << A.GetNormalized() << std::endl;
    std::cout << Bbis << " normal is " << Bbis.GetNormalized() << std::endl;
    std::cout << B << " normal is " << B.GetNormalized() << std::endl;
    std::cout << Cbis << " normal is " << Cbis.GetNormalized() << std::endl;
    std::cout << C << " normal is " << C.GetNormalized() << std::endl;
    std::cout << Dbis << " normal is " << Dbis.GetNormalized() << std::endl;
    std::cout << D << " normal is " << D.GetNormalized() << std::endl;
    std::cout << Ebis << " normal is " << Ebis.GetNormalized() << std::endl;
    std::cout << E << " normal is " << E.GetNormalized() << std::endl;
    std::cout << Fbis << " normal is " << Fbis.GetNormalized() << std::endl;
    std::cout << F << " normal is " << F.GetNormalized() << std::endl;
    std::cout << Gbis << " normal is " << Gbis.GetNormalized() << std::endl;
    std::cout << G << " normal is " << G.GetNormalized() << std::endl;
    std::cout << Hbis << " normal is " << Hbis.GetNormalized() << std::endl;
    std::cout << H << " normal is " << H.GetNormalized() << std::endl;

    std::cout << Abis << " normalized is ";
    Abis.Normalize();
    std::cout << Abis << std::endl;

    std::cout << A << " normalized is ";
    A.Normalize();
    std::cout << A << std::endl;

    std::cout << Bbis << " normalized is ";
    Bbis.Normalize();
    std::cout << Bbis << std::endl;

    std::cout << B << " normalized is ";
    B.Normalize();
    std::cout << B << std::endl;

    std::cout << Cbis << " normalized is ";
    Cbis.Normalize();
    std::cout << Cbis << std::endl;

    std::cout << C << " normalized is ";
    C.Normalize();
    std::cout << C << std::endl;

    std::cout << Dbis << " normalized is ";
    Dbis.Normalize();
    std::cout << Dbis << std::endl;

    std::cout << D << " normalized is ";
    D.Normalize();
    std::cout << D << std::endl;

    std::cout << Ebis << " normalized is ";
    Ebis.Normalize();
    std::cout << Ebis << std::endl;

    std::cout << E << " normalized is ";
    E.Normalize();
    std::cout << E << std::endl;

    std::cout << Fbis << " normalized is ";
    Fbis.Normalize();
    std::cout << Fbis << std::endl;

    std::cout << F << " normalized is ";
    F.Normalize();
    std::cout << F << std::endl;

    std::cout << Gbis << " normalized is ";
    Gbis.Normalize();
    std::cout << Gbis << std::endl;

    std::cout << G << " normalized is ";
    G.Normalize();
    std::cout << G << std::endl;

    std::cout << Hbis << " normalized is ";
    Hbis.Normalize();
    std::cout << Hbis << std::endl;

    std::cout << H << " normalized is ";
    H.Normalize();
    std::cout << H << std::endl;

    Vec2PerfTests();
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
