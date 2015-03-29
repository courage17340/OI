type
  arr=record
        v,z:longint;
      end;
var
 a:array[0..1000,0..1000] of 0..1;
 i,j,m,k,x,y,x1,x2,y1,y2:longint;
procedure p(var a,b:longint);
var t:longint;
begin
 if a<b then exit;
 t:=a;a:=b;b:=t;
end;
begin
 readln(y,x,k);
 fillchar(a,sizeof(a),0);
 for m:=1 to k do
  begin
   readln(x1,y1,x2,y2);
   p(x1,x2);
   p(y1,y2);
   for i:=x1 to x2 do for j:=y1 to y2 do a[j,i]:=1;
  end;
 k:=0;
 for i:=1 to x do for j:=1 to y do if a[i,j]=1 then inc(k);
 writeln(k);
end.