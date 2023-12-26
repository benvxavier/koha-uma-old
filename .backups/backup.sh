DB_USER="root"
DB_PASS="root"
BACKUP_DIR="/usr/share/koha/.backups"

# Timestamp (para nomes de arquivos de backup exclusivos)
TIMESTAMP=$(date +"%Y%m%d_%H%M%S")

# Verifica se o diretório de backup existe, se não cria.
if [ ! -d "$BACKUP_DIR" ]; then
    mkdir -p $BACKUP_DIR
fi

# mysqldump command
mysqldump -u $DB_USER -p$DB_PASS koha_metodista > $BACKUP_DIR/koha_metodista-backup$TIMESTAMP.sql