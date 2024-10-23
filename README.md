``` bash
echo 'zone "gryffindor.hogwarts.D35.com" {
        type master;
        file "/etc/bind/hogwarts/gryffindor.hogwarts.D35.com";
};

zone "ravenclaw.hogwarts.D35.com" {
        type master;
        file "/etc/bind/hogwarts/ravenclaw.hogwarts.D35.com";
};' > /etc/bind/named.conf.local

penutup
