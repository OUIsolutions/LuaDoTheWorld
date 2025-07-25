#### Build from scratch

for buiding from scratch you need to have [darwin](https://github.com/OUIsolutions/Darwin) installed on your machine, for install darwin:
```bash
curl -L https://github.com/OUIsolutions/Darwin/releases/download/0.020/darwin.out -o darwin.out && chmod +x darwin.out &&  sudo  mv darwin.out /usr/bin/darwin
```
then you can build the project with in the root dir of the project:
```bash
darwin run_blueprint build/  --mode folder build_release
```
