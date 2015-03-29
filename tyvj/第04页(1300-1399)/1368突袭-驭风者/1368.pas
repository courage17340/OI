const
  jc:array[0..10] of longint=(1,1,2,6,24,120,720,5040,40320,362880,3628800);
  n=10;
var
  s:ansistring;
  i,j,x,k,t,ans,y:longint;
  a,b:array[0..10] of 0..1;
begin
  readln(s);
  fillchar(a,sizeof(a),0);
  if length(s)>7 then begin writeln('No!');halt;end;
  val(s,x,j);
  ans:=0;
  for k:=1 to 2047 do
    begin
      i:=n;
      while a[i]=1 do i:=i-1;
      a[i]:=1;
      for j:=i+1 to n do a[j]:=0;
      t:=0;y:=0;
      for i:=0 to 10 do if a[i]=1 then begin t:=t+jc[i];y:=y+i;end;
      if (t=x)and(y>ans) then begin for i:=0 to 10 do b[i]:=a[i];ans:=y;end;
    end;
  if ans=0 then begin writeln('No!');halt;end;
  for i:=0 to 10 do if b[i]=1 then break;
  write(x,'=',i,'!');
  for j:=i+1 to 10 do if b[j]=1 then write('+',j,'!');
  writeln;
end.