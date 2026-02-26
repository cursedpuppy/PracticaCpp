import librosa
import soundfile as sf
import numpy as np
import os  # <-- Importamos os

def transformador_paleoacustico(nombre_entrada, nombre_salida, factor_escala):
    # Obtener la ruta de la carpeta donde reside este script
    ruta_base = os.path.dirname(os.path.abspath(__file__))
    
    # Construir rutas completas uniendo la carpeta con el nombre del archivo
    archivo_entrada = os.path.join(ruta_base, nombre_entrada)
    archivo_salida = os.path.join(ruta_base, nombre_salida)

    # Verificar si el archivo de entrada realmente existe
    if not os.path.exists(archivo_entrada):
        print(f"Error: No se encuentra el archivo {nombre_entrada} en {ruta_base}")
        return

    # 1. Cargar el audio
    y, sr = librosa.load(archivo_entrada)

    # 2. Calcular semitonos (relación logarítmica)
    semitonos = -12 * np.log2(factor_escala)
    print(f"Modificando audio... Bajando {semitonos:.2f} semitonos")

    # 3. Cambio de Pitch
    y_grave = librosa.effects.pitch_shift(y, sr=sr, n_steps=semitonos)

    # 4. Simular resonancia (Time Stretch)
    y_final = librosa.effects.time_stretch(y_grave, rate=0.8)

    # 5. Guardar el resultado en la misma carpeta
    sf.write(archivo_salida, y_final, sr)
    print(f"¡Rugido generado con éxito en: {archivo_salida}!")

# Uso: Solo pasas los nombres, el script localiza la ruta automáticamente
transformador_paleoacustico('cotorraCachana.wav', 'dino_output.wav', factor_escala=5)
