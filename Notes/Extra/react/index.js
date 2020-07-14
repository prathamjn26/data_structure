import React, {Suspense, lazy, Component} from 'react';
import {BrowserRouter as Router, Switch, Route} from 'react-router-dom';
import {Spin} from 'antd';
// import TestDetail from '../../../TestDetail/components/TestDetail';

import First from '../Test/First';

import Result from '../result/components/result';
import Category from '../category_home_page/Category';
import CategoryHome from '../category_home_page/components/Main';
import Second from '../Test/Second';
import Third from '../Test/Third';
import Feedback from '../Test/Feedback';
import Loading from '../components/global/loading/loading';
import Home from '../landing/Home';
import PrivateRoute from './private_routes';
import QuestionLibrary from '../Question_Library/Library';
import history from './history';
import Institute from '../institute_home_page/instituteHome';
const DashboardHOC = lazy(() => import('../dashboard/hoc/dashboard'));
const PageNotFound = lazy(() =>
  import('../components/global/error/page_not_found/page_not_found')
);
const About = lazy(() => import('../components/home/about'));
const ContactUs = lazy(() => import('../landing/Home/contact-us'));

class CustomRouter extends Component {
  constructor(props) {
    super(props);
    this.state = {loading: true};
  }
  componentDidMount() {
    this.setState({loading: false});
  }

  render() {
    let renderContent = [];
    if (this.state.loading) {
      renderContent.push(
        <div className="spin-list">
          <Spin spinning={this.state.loading}>from inside custome router</Spin>
        </div>
      );
    } else {
      renderContent.push(
        <Router history={history}>
          <Suspense
            fallback={
              <div>
                <Loading />
              </div>
            }
          >
            <Switch>
              <Route exact path="/" component={Home} />
              <Route
                exact
                path="/category/:category"
                component={CategoryHome}
              />
              <Route exact path="/category/" component={Category} />

              <Route path="/dashboard/" component={DashboardHOC} />
              <PrivateRoute exact path="/first/:id" component={First} />
              <PrivateRoute exact path="/first/second/:id" component={Second} />
              <Route
                exact
                path="/institute/:institute/"
                component={Institute}
              />
              <Route
                exact
                path="/questionlibrary/"
                component={QuestionLibrary}
              />
              <PrivateRoute
                exact
                path="/first/second/third/:id"
                component={Third}
              />
              <PrivateRoute exact path="/result/:id" component={Result} />

              <Route exact path="/feedback/:id" component={Feedback} />
              <Route exact path="/about/" component={About} />
              <Route exact path="/contact-us/" component={Home} />
              <Route component={PageNotFound} />
            </Switch>
          </Suspense>
        </Router>
      );
    }

    return <>{renderContent}</>;
  }
}

export default CustomRouter;
