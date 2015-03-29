var
  n,i,j,k,x,y,k1,k2:longint;
  f1:int64;
  ans:real;
procedure work;
var i:longint;
begin
  i:=x*x-(k-1)*y;
  ans:=i/k;
  writeln(ans:0:6);
end;
begin
  readln(n);
  for i:=1 to n do
    begin
      readln(k,x,y);
      if k=1 then
        begin
          if y=x*x then writeln(y,'.000000') else writeln('WA RE CE TLE MLE OLE');
          continue;
        end;
      k1:=4*x*x;
      k2:=4*(x*x-(k-1)*y);
      f1:=int64(int64(k1)-int64(k)*int64(k2));
      if f1<0 then writeln('WA RE CE TLE MLE OLE')
              else work;
    end;
  readln;
end.