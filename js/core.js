class Point {
    constructor(x,y,z) {
	this.x = x;
	this.y = y;
	this.z = z;
    }
    
    normalize() {
	let norm = Math.hypot(this.x, this.y, this.z);
	this.x = this.x / norm;
	this.y = this.y / norm;
	this.z = this.z / norm;

	return this;
    }
};


function middle(a,b){
    return new Point((a.x + b.x) / 2.0,
		     (a.y + b.y) / 2.0,
		     (a.z + b.z) / 2.0);
}

class App
{
    constructor() {
	let e = 1.0;
	
	this.points = [new Point(e,0,0),
		       new Point(0,e,0),
		       new Point(-e,0,0),
		       new Point(0,-e,0),
		       new Point(0,0,e),
		       new Point(0,0,-e)];
		
	this.triangles = [[0,1,4],
			  [1,2,4],
			  [2,3,4],
			  [3,0,4],
			  [1,0,5],
			  [2,1,5],
			  [3,2,5],
			  [0,3,5]];
    }
    
    run(rec) {

	let i = 0;
	let j = 0;
	let  newtriangles = [];

	for(i = 0; i < rec ; i++){
	    let l = this.triangles.length;

	    for(j = 0; j < l ; j++){
		let [i1, i2, i3] = this.triangles[j];
		
		let a = this.points[i1];
		let b = this.points[i2];
		let c = this.points[i3];

		this.points.push(middle(a,b).normalize());
		this.points.push(middle(b,c).normalize());
		this.points.push(middle(a,c).normalize());
				
		let npi1 = this.points.length - 3; // d
		let npi2 = this.points.length - 2; // e
		let npi3 = this.points.length - 1; // f
		
		newtriangles.push(new Array(i1,npi1,npi3));
		newtriangles.push(new Array(i2,npi2,npi1));
		newtriangles.push(new Array(i3,npi3,npi2));
		newtriangles.push(new Array(npi1,npi2,npi3));		
	    }

	    this.triangles.splice(0,this.triangles.length);
	    
	    for(j=0; j<newtriangles.length; j++)
	    {
		this.triangles.push(newtriangles[j]);
	    }
	    
	}	
    }

    getPoints() {
	return this.points;
    }
    
    getTriangles () {
	return this.triangles;
    }    
};
