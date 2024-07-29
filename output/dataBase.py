import sqlite3







def post(age: int, name: string, password: string, ):
	'''posts Users with the following fields
	age, name, password, '''
	conn = sqlite3.connect('users.db')
	query = 'INSERT INTO users(age, name, password, ) VALUES(age, name, password, )'
	with conn:
		cur = conn.cursor()
		cur.execute(query, (age, name, password, ))
		conn.commit()
def get(id: int) -> list[tuple]|None:
	'''gets Users by id with the following fields
	age, name, password, id'''
	conn = sqlite3.connect('users.db')
	query = 'SELECT age, name, password, id FROM users WHERE id = ?'
	with conn:
		cur = conn.cursor()
		cur.execute(query, (id,))
		return cur.fetchone()
def delete(id):
	conn = sqlite3.connect('users.db')
	query = 'DELETE FROM users WHERE id = ?'
	with conn:
		cur = conn.cursor()
		cur.execute(query, (id,))
		conn.commit()
def put(age: int, name: string, password: string, ):
	'''puts Users with the following fields
	age, name, password, '''
	conn = sqlite3.connect('users.db')
	query = 'UPDATE users SET age = ?, name = ?, password = ?,  WHERE id = ?'
	with conn:
		cur = conn.cursor()
		cur.execute(query, (age, name, password, ))
		conn.commit()
