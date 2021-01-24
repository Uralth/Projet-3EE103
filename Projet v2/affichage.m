clear all
close all

%% Ouverture des fichiers
fileU = fopen('Untitled.txt','r');
fileV = fopen('Untitled 2.txt','r');
img = imread('untitled.bmp');

%Lecture des données
A = fscanf(fileU,"%f");
A1 = fscanf(fileV,"%f");

%Dimensions de la matrice
dim = A(1:2).';

%Capture des données d'images (2 premieres valeurs = dimensions)
B = A(3:end);
B1 = A1(3:end);

%Formattage aux dimensions appropriees
B = reshape(B, dim);
B1 = reshape(B1, dim);

%Affichage de l'image
figure
image(img);

%Traçage des vecteurs
figure
quiver(B,B1);


