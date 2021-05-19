# Install SDL2, SDL2_image, and SDL2_TTF


# Make and clean dirs
if [[ -d tmp ]]
then
	rm -rf tmp
fi

if [[ -d SDL_FULL ]]
then
	rm -rf SDL_FULL
fi

if [[ -d executable ]]
then
	rm -rf executable
fi

mkdir tmp
mkdir SDL_FULL
mkdir executable

cd SDL_FULL
mkdir x86
mkdir include
cd ../

# Install SDL2
cd tmp
if ! wget https://www.libsdl.org/release/SDL2-devel-2.0.14-VC.zip
then
	echo "Could not download SDL2."
	exit 1
fi

unzip SDL2-devel-2.0.14-VC.zip

rm SDL2-devel-2.0.14-VC.zip

cd ../

mv tmp/SDL2-2.0.14/include/*.h SDL_FULL/include
mv tmp/SDL2-2.0.14/lib/x86/*.lib SDL_FULL/x86
mv tmp/SDL2-2.0.14/lib/x86/*.txt executable
mv tmp/SDL2-2.0.14/lib/x86/*.dll executable

# Install SDL2_image
cd tmp
if ! wget https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.5-VC.zip
then 
	echo "Could not download SDL2_image."
	exit 1
fi

unzip SDL2_image-devel-2.0.5-VC.zip

rm SDL2_image-devel-2.0.5-VC.zip

cd ../


mv tmp/SDL2_image-2.0.5/include/*.h SDL_FULL/include/
mv tmp/SDL2_image-2.0.5/lib/x86/*.lib SDL_FULL/x86
mv tmp/SDL2_image-2.0.5/lib/x86/*.txt executable
mv tmp/SDL2_image-2.0.5/lib/x86/*.dll executable

# Install SDL2_TTF
cd tmp
if ! wget https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-devel-2.0.15-VC.zip
then 
	echo "Could not download SDL2_ttf"
	exit 1
fi

unzip SDL2_ttf-devel-2.0.15-VC.zip

rm SDL2_ttf-devel-2.0.15-VC.zip

cd ../

mv tmp/SDL2_ttf-2.0.15/include/*.h SDL_FULL/include
mv tmp/SDL2_ttf-2.0.15/lib/x86/*.lib SDL_FULL/x86
mv tmp/SDL2_ttf-2.0.15/lib/x86/*.txt executable
mv tmp/SDL2_ttf-2.0.15/lib/x86/*.dll executable


rm -rf tmp

echo "Installation complete. Run compile.bash to compile project."





