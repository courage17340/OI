var
  x,y:array[1..4] of double;
  ans,i,j:longint;
  s1,s2,s3,s4:double;
  s:string;
function f(i,j,k:longint):double;
var a,b,c,p:double;
begin
  a:=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
  b:=sqrt(sqr(x[i]-x[k])+sqr(y[i]-y[k]));
  c:=sqrt(sqr(x[j]-x[k])+sqr(y[j]-y[k]));
  p:=(a+b+c)/2;
  f:=sqrt(p*(p-a)*(p-b)*(p-c));
end;
function yes(i,j:longint):boolean;
begin
  if (ord(x[4]>x[i])+ord(x[4]>x[j])<>1) or (ord(y[4]>y[i])+ord(y[4]>y[j])<>1) then exit(false);
  if x[i]=x[j] then if x[i]<>x[4] then exit(false) else exit(true);
  if (y[i]-y[j])*(x[j]-x[4])=(x[i]-x[j])*(y[j]-y[4]) then exit(true);
  exit(false);
end;
begin
  for i:=1 to 4 do
    begin
      readln(s);
      delete(s,1,1);
      j:=pos(',',s);
      val(copy(s,1,j-1),x[i]);
      delete(s,1,j);
      delete(s,length(s),1);
      val(s,y[i]);
    end;
  s1:=f(1,2,4);
  s2:=f(1,3,4);
  s3:=f(2,3,4);
  s4:=f(1,2,3);
  ans:=0;
  for i:=1 to 3 do if (x[i]=x[4])and(y[i]=y[4]) then ans:=4;
  if ans>0 then begin writeln(ans);readln;halt;end;
  for i:=1 to 2 do
    for j:=i+1 to 3 do
      if yes(i,j) then ans:=3;
  if ans>0 then begin writeln(ans);readln;halt;end;
  if abs(s1+s2+s3-s4)<0.001 then writeln(1) else writeln(2);
  readln;
end.