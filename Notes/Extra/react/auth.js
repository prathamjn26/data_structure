import { checkStorage, setStorage } from '../auth/utils/cookies';

const Auth = {
  isAuthenticated: true,

  authenticate() {
    this.isAuthenticated = true;
  },

  getAuth() {
    const user = checkStorage();
    return true;
  }
};

export default Auth;
