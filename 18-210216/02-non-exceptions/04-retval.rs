// Go, Rust, Haskell.

// До
fn read_people() -> Result<People, String> {
    match open() {
        Ok(f) => {
           // ....
        }
        Err(err) => return Err(err) /* не умеет обрабатывать, сообщаем наверх */
    }
}

// После
fn read_people() -> Result<People, String> {
    let f = open()?;
    ...
}
