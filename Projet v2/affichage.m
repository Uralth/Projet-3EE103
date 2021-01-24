clear all
close all

%% Horn & Schunck 
%Ouverture des fichiers
fileU = fopen('Frame 1.txt','r');
fileV = fopen('Frame 2.txt','r');
img = imread('Frame 1.bmp');
img2 = imread('Frame 2.bmp');

%Lecture des donn�es
A = fscanf(fileU,"%f");
A1 = fscanf(fileV,"%f");

%Dimensions de la matrice
dim = A(1:2).';

%Capture des donn�es d'images (2 premieres valeurs = dimensions)
B = A(3:end);
B1 = A1(3:end);

%Formattage aux dimensions appropriees
B = reshape(B, dim);
B1 = reshape(B1, dim);

%Affichage des images
figure
image(img);
title('Frame 1');

figure
image(img2);
title('Frame 2');

%Tra�age des vecteurs (non superpos�e car axes x,y en C differents)
figure
quiver(B,B1);
title('M�thode de Horn & Schunck');

%% Multi-r�solution 
%Ouverture des fichiers
fileU = fopen('Frame 1i.txt','r');
fileV = fopen('Frame 2i.txt','r');

%Lecture des donn�es
A = fscanf(fileU,"%f");
A1 = fscanf(fileV,"%f");

%Dimensions de la matrice
dim = A(1:2).';

%Capture des donn�es d'images (2 premieres valeurs = dimensions)
B = A(3:end);
B1 = A1(3:end);

%Formattage aux dimensions appropriees
B = reshape(B, dim);
B1 = reshape(B1, dim);

%Tra�age des vecteurs (non superpos�e car axes x,y en C differents)
figure
quiver(B,B1);
title('M�thode de Horn & Schunck, multi-r�solution avec n = 2');


