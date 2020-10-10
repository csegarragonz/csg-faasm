+ Set up the correct ansible version
```bash
cd <experiments repo>
source third-party/faasm/workon.sh
pip install -U ansible
cd ansible 
<ansible commands>
```

+ Run ansible-related commands
```bash
cd ansible
ansible-playbook -i ../third-party/faasm/ansible/inventory/bare_metal.yml openmpi.yml
```
