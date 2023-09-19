import sys
from PIL import Image

# Carregue a imagem JPEG
imagem_jpeg = Image.open(sys.argv[1])

# Obtenha as dimensões da imagem
largura, altura = imagem_jpeg.size

# Crie um arquivo PPM e escreva o cabeçalho
with open('imagem.ppm', 'w') as arquivo_ppm:
    arquivo_ppm.write(f'P3\n{largura} {altura}\n255\n')

    # Itere sobre cada pixel da imagem e escreva as informações de cor no formato PPM
    for y in range(altura):
        for x in range(largura):
            pixel = imagem_jpeg.getpixel((x, y))
            r, g, b = pixel
            arquivo_ppm.write(f'{r} {g} {b} ')
        arquivo_ppm.write(f'\n')
        

print("Imagem JPEG convertida para PPM com sucesso!")

