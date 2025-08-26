

# 🧊 Cube3D

**Cube3D** es un juego 3D simple estilo *Wolfenstein 3D*, desarrollado en C usando la librería gráfica MiniLibX (MLX). Renderiza un mundo 3D en tiempo real a partir de un mapa 2D utilizando técnicas de raycasting.

## 📦 Requisitos

Antes de compilar el proyecto, asegúrate de tener las siguientes dependencias instaladas en tu sistema:

```bash
sudo apt update && sudo apt install -y \
  build-essential \
  cmake \
  libxext-dev \
  libx11-dev \
  libbsd-dev \
  libxrandr-dev \
  libxi-dev \
  libgl1-mesa-dev \
  libglfw3 \
  libglfw3-dev

```

> 💡 *Nota*: Estas dependencias son necesarias para compilar y ejecutar la librería MiniLibX (MLX) en Linux.

---

## 🚀 Instalación

Clona este repositorio **recursivamente** para incluir los submódulos necesarios (como MLX):

```bash
git clone --recurse-submodules git@github.com:Leined18/Cube3D.git
cd Cube3D
make or make bonus
or
make dmap or make bmap -> para compilar y ejecutar el primer mapa; dmap -> default; bmap -> bonus
```

> Si ya habías clonado el repositorio sin `--recurse-submodules`, puedes correr esto para arreglarlo:
>
> ```bash
> git submodule update --init --recursive
> ```

---

## 🕹️ Cómo jugar

Una vez compilado, ejecuta el juego así:

```bash
./cub3d ./default/assets/maps/scene_1.cub
or
./cub3d_bonus ./bonus/assets/maps/scene_1.cub
```

Usa las teclas para moverte por el mapa renderizado en 3D.

---

## 🛠️ Tecnologías

* **C** (lenguaje principal)
* **MiniLibX** (para renderizado gráfico)
* **Raycasting** (para generar el efecto 3D)
* **Makefile** (para automatizar la compilación)

---

## 🧠 Autores

Desarrollado por [mvidal-h](https://github.com/MiguelViHe) && [danpalac](https://github.com/Leined18)  como parte del proyecto en la escuela 42.

---

