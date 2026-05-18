# evofox-blaze
A userland driver to control RGB effects of evofox blaze mouse

## Installation
You will need to install libhidapi-dev  library.  
```bash 
sudo apt install libhidapi-dev
```

## Compiling
```bash
make
```

## Running
```bash
./evofox-blaze
```

## !WARNING
This project interacts directly with hardware using reverse engineered protocols. While we do our best to make sure we're sending the right data, there is always some risk in sending data to hardware when we don't understand exactly how that hardware works. This can cause issues with certain hardware getting damaged/bricked. By installing and using this software you accept this risk.
