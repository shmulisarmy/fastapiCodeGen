let React, ReactDOM;
const { useState, useRef, useEffect, useMemo, useCallback, useContext, createContext } = React
type Users = {
    age: number,
    name: string,
    password: string,
};
function Users({users}: {users: Users}) {
    const [placeholder, setPlaceholder] = React.useState()
    const rerender = () => setPlaceholder(!placeholder);
    return (
        <div className='users'>
            <p>age: {users.age}</p>
            <p>name: {users.name}</p>
            <p>password: {users.password}</p>
        </div>
    );
}
function App() {
    return (
        <div className="App">
            <h1>Wellcome to usersapp </h1>
            <h2>Start editing to see some magic happen!</h2>
            <div className="users-container">
                {users.map((users) => < userskey={users.id} users={users} />)}
            </div>
        </div>
    );
}
ReactDOM.render(<users users={users[0]}/>, document.getElementById('root'))
