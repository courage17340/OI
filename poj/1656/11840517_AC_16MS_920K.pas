var
  a:array[1..100,1..100] of longint;
  n,i,j,ans,x,y,L,k:longint;
  ch,c:char;
begin
  readln(n);
  fillchar(a,sizeof(a),0);
  for k:=1 to n do
    begin
      read(ch);
      c:=ch;
      while c in ['A'..'Z'] do read(c);
      readln(x,y,L);
      case ch of
        'B':for i:=x to x+L-1 do
              for j:=y to y+L-1 do
                a[i,j]:=1;
        'W':for i:=x to x+L-1 do
              for j:=y to y+L-1 do
                a[i,j]:=0;
        'T':begin
              ans:=0;
              for i:=x to x+L-1 do
                for j:=y to y+L-1 do
                  inc(ans,a[i,j]);
              writeln(ans);
            end;
      end;
    end;
end.