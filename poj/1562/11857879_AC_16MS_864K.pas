type rec=record x,y:longint;end;
var
  a:array[0..101,0..101] of char;
  f:array[1..8,1..2] of longint=((1,1),(1,0),(1,-1),(0,1),(0,-1),(-1,1),(-1,0),(-1,-1));
  n,m,i,j,k,p,q,ans:longint;
  b:array[1..10000] of rec;
begin
  while true do
    begin
      readln(n,m);
      if n+m=0 then break;
      for i:=0 to n+1 do
        for j:=0 to m+1 do
          a[i,j]:='*';
      for i:=1 to n do
        begin
          for j:=1 to m do read(a[i,j]);
          readln;
        end;
      ans:=0;
      for p:=1 to n do
        for q:=1 to m do
          if a[p,q]='@' then
            begin
              inc(ans);
              i:=1;
              j:=1;
              b[1].x:=p;
              b[1].y:=q;
              a[p,q]:='*';
              while i<j+1 do
                begin
                  for k:=1 to 8 do if a[b[i].x+f[k,1],b[i].y+f[k,2]]='@' then
                    begin
                      inc(j);
                      b[j].x:=b[i].x+f[k,1];
                      b[j].y:=b[i].y+f[k,2];
                      a[b[j].x,b[j].y]:='*';
                    end;
                  inc(i);
                end;
            end;
      writeln(ans);
   end;
end.