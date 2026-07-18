#!/bin/bash

counter=1

while IFS= read -r line; do
    echo "$line" | piper-tts \
        --model ~/.local/share/piper/voices/en_GB-cori-high.onnx \
        --output_file "${counter}.wav"

    ((counter++))
done < splash.txt