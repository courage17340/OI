type
  rec=record x,y:longint;end;
var
  a:array[1..21,1..3] of rec;
  n,i,j,k,a0,m,x:longint;
begin
  fillchar(a,sizeof(a),0);
  readln(a0,n,m,x);
  a[1,1].x:=1;a[1,1].y:=0;
  a[1,2].x:=0;a[1,2].y:=0;
  a[1,3].x:=1;a[1,3].y:=0;
  a[2,1].x:=0;a[2,1].y:=1;
  a[2,2].x:=0;a[2,1].y:=1;
  a[2,3].x:=1;a[2,3].y:=0;
  for i:=3 to n-1 do
    begin
      a[i,1].x:=a[i-1,1].x+a[i-2,1].x;
      a[i,1].y:=a[i-1,1].y+a[i-2,1].y;
      a[i,2].x:=a[i-1,1].x;
      a[i,2].y:=a[i-1,1].y;
      a[i,3].x:=a[i-1,3].x+a[i,1].x-a[i,2].x;
      a[i,3].y:=a[i-1,3].y+a[i,1].y-a[i,2].y;
    end;
  if trunc((m-a[n-1,3].x*a0)/a[n-1,3].y)=(m-a[n-1,3].x*a0)/a[n-1,3].y
    then
      begin
        k:=(m-a[n-1,3].x*a0) div a[n-1,3].y;
        writeln(a[x,3].x*a0+a[x,3].y*k);
      end
    else
      writeln('No answer.');
end.