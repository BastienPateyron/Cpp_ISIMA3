#include "catch.hpp"

#include <array>

#include <item.hpp>
#include <arme.hpp>
#include <inventaire.hpp>
#include <enchantement.hpp>

using Inv = Inventaire;
// using Inv = Inventaire<TrieurAlphabetique>;

/*
 Tests 1 et 2 : Constructeurs d'items
 */
TEST_CASE ( "Item:Constructeur" ) {
    const char * nom = "Baton";
    const Item baton(nom);

    REQUIRE ( baton.getNom() == "Baton" );
    REQUIRE ( baton.getNom() == nom );
    REQUIRE ( baton.estVendable() == false );
    REQUIRE ( baton.getPrix() == 0 );
    
    const Item livre("Livre", 12);

    REQUIRE ( livre.getNom() == "Livre" );
    REQUIRE ( livre.estVendable() == true );
    REQUIRE ( livre.getPrix() == 12 );
}

TEST_CASE ( "Item:ConstructeurParCopie" ) {
    const Item item("Livre", 12);
    const Item copie(item);

    REQUIRE ( item.getNom() == copie.getNom() );
    REQUIRE ( item.estVendable() == copie.estVendable() );
    REQUIRE ( item.getPrix() == copie.getPrix() );
}

/*
 * Tests 3 : Arme
 */
TEST_CASE ( "Arme:Utilisation" ) {
    Arme arme("Baton de combat", 0, 10);
    
    REQUIRE ( arme.getNom() == "Baton de combat [10]" );
    REQUIRE ( arme.estVendable() ==  false);

    for (unsigned i = 0; i < 10; ++i)
    {  
        REQUIRE ( arme.getNom() == "Baton de combat [" + std::to_string(10-i) + "]" );
        arme.utiliser();
    }

    REQUIRE_THROWS ( arme.utiliser() );
}

/*
 * Test 4 : Exception
 */
TEST_CASE ( "Arme:Exception" ) {
    Arme item("Petard mouillé", 0, 0);

    REQUIRE_THROWS_AS ( item.utiliser(), Arme::DestroyedItemException ); 
}

/*
 * Test 5 & 6 : Enchantement
 */
TEST_CASE ( "Arme:Enchantement" ) {
    Enchantement * enchantement = new Enchantement(3.2f);
    Arme epee("Epee", 0, 10);

    REQUIRE ( epee.getEnchantement() == nullptr );
    epee.enchanter(enchantement);

    REQUIRE ( epee.getEnchantement() == enchantement );
}

TEST_CASE ( "Arme:Constructeur copie" ) {
    Enchantement * enchantement = new Enchantement(3.2f);
    Arme epee("Excalibur", 0, 10);

    epee.enchanter(enchantement);
    Arme copie = epee;

    REQUIRE ( copie.getEnchantement() != epee.getEnchantement() );
    REQUIRE ( copie.getEnchantement()->getPuissance() == epee.getEnchantement()->getPuissance() );
}

// /*
//  * Test 7 & 8 : Déplacement
//  */
// TEST_CASE ( "Arme:Constructeur déplacement" ) {
//     Enchantement * enchantement = new Enchantement(3.2f);
//     Arme epeeVictime("Excalibur", 3, 10);

//     epeeVictime.enchanter(enchantement);
//     Arme epee(std::move(epeeVictime));

//     REQUIRE ( epee.getEnchantement() == enchantement );
//     REQUIRE ( epee.getNom() == "Excalibur [10]" );
//     REQUIRE ( epee.getPrix() == 3 );

//     REQUIRE ( epeeVictime.getEnchantement() == nullptr );
//     REQUIRE ( static_cast<Item>(epeeVictime).getNom() == "" );
//     REQUIRE ( epeeVictime.getPrix() == 0 );


//     // Autre manière de vérifier la présence du constructeur, mais pas de vérifier son bon fonctionnement.
//     REQUIRE (std::is_move_constructible<Arme>::value);
// }

// TEST_CASE ( "Arme:Affectation par déplacement" ) {
//     // J'ai pas trouver mieux, essayer de la faire bien cette redéfinition d'opérateur.
//     REQUIRE (std::is_move_assignable<Arme>::value);
// }

/*
 * Test 9 : Un container
 */
TEST_CASE ( "Inventaire:Stokage" ) {
    Inv inventaire;
    const Inv inventaire2;
    
    REQUIRE (inventaire.getTaille() == 0);

    inventaire.ajouter(new Item("Effectiv Modern C++", 15));
    REQUIRE (inventaire.getTaille() == 1);

    REQUIRE (inventaire2.getTaille() == 0);
}

/*
 * Test 10 : Enum
 */
TEST_CASE ( "Inventaire:Catégorie" ) {
    Inv::Categorie categorie = Inv::Categorie::ARME; 

    REQUIRE ( static_cast<char>(categorie) == 'A' );
    REQUIRE ( static_cast<char>(Inv::Categorie::CONSOMMABLE) == 'C' );
    REQUIRE ( static_cast<char>(Inv::Categorie::RARE) == 'R' );
}

/*
 * Test 11 : Catégorisation des items de l'inventaire
 */
TEST_CASE ( "Inventaire:Catégorisation" ) {
    Inv inventaire;
    Inv::list_t const & itemsRares = inventaire.getItemsParCategorie(Inv::Categorie::RARE);
    Inv::list_t const & itemsNormaux = inventaire.getItemsParCategorie(Inv::Categorie::NORMAL);
    Inv::list_t const & itemsArmes = inventaire.getItemsParCategorie(Inv::Categorie::ARME);
    Inv::list_t const & itemsConsommables = inventaire.getItemsParCategorie(Inv::Categorie::CONSOMMABLE);

    inventaire.ajouter(new Item("Graal"), Inv::Categorie::RARE);
    inventaire.ajouter(new Item("Bâton"));

    REQUIRE ( itemsRares.size() == 1 );
    REQUIRE ( itemsNormaux.size() == 1 );
    REQUIRE ( itemsArmes.size() == 0 );
    REQUIRE ( itemsConsommables.size() == 0 );
}

/*
 * Test 12 : Tri
 */
TEST_CASE ( "Inventaire:Tri" ) {
    Inv inventaire;
    std::array<std::string, 4> array = {"Amulette", "Bâton", "Livre", "Xylophone"};

    Inv::list_t const & itemsNormaux = inventaire.getItemsParCategorie(Inv::Categorie::NORMAL);
    
    inventaire.ajouter(new Item("Bâton"));
    inventaire.ajouter(new Item("Livre"));
    inventaire.ajouter(new Item("Amulette"));
    inventaire.ajouter(new Item("Xylophone")); // Grave chelou d'avoir un xylophone...

    unsigned i = 0;
    std::for_each(itemsNormaux.cbegin(), itemsNormaux.cend(), [&array, &i](Item * item){
        REQUIRE ( item->getNom() == array[i++] );
    });
}

// /*
//  * Test 13 : Plus de tris
//  */
// TEST_CASE ( "Inventaire:Tris sélectifs" ) {
//     Inventaire<TrieurAlphabetique> inventaire;
//     std::array<std::string, 4> array = {"Amulette", "Bâton", "Livre", "Xylophone"};

//     Inv::list_t const & itemsNormaux = inventaire.getItemsParCategorie(Inv::Categorie::NORMAL);
    
//     inventaire.ajouter(new Item("Bâton"));
//     inventaire.ajouter(new Item("Livre"));
//     inventaire.ajouter(new Item("Amulette"));
//     inventaire.ajouter(new Item("Xylophone")); // Grave chelou d'avoir un xylophone...

//     unsigned i = 0;
//     std::for_each(itemsNormaux.cbegin(), itemsNormaux.cend(), [&array, &i](Item * item){
//         REQUIRE ( item->getNom() == array[i++] );
//     });


//     Inventaire<TrieurPrix> inventaire2;
//     std::array<std::string, 4> array2 = {"Livre", "Amulette", "Bâton", "Xylophone"};

//     Inv::list_t const & itemsNormaux2 = inventaire.getItemsParCategorie(Inv::Categorie::NORMAL);
    
//     inventaire2.ajouter(new Item("Bâton", 89));
//     inventaire2.ajouter(new Item("Livre", 19));
//     inventaire2.ajouter(new Item("Amulette", 35));
//     inventaire2.ajouter(new Item("Xylophone", 465)); // Grave cher en plus...

//     i = 0;
//     std::for_each(itemsNormaux2.cbegin(), itemsNormaux2.cend(), [&array, &i](Item * item){
//         REQUIRE ( item->getNom() == array[i++] );
//     });
// }

// /*
//  * Test 14 : Item ou arme ?
//  */
// TEST_CASE ( "Inventaire:Item ou Arme" ) {
//     Inv inventaire;
//     inventaire.ajouter(new Arme("Gourdin"));
    
//     inventaire.ajouter(static_cast<Item*>(new Arme("Gourdin")));
//     Inv::list_t const & itemsNormaux = inventaire.getItemsParCategorie(Inv::Categorie::NORMAL);
//     Inv::list_t const & itemsArmes = inventaire.getItemsParCategorie(Inv::Categorie::ARME);
   
//     REQUIRE ( itemsNormaux.size() == 0 );
//     REQUIRE ( itemsArmes.size() == 1 );
// }